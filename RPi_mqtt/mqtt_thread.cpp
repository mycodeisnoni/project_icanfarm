#include <iostream>
#include <cstring>
#include <chrono>
#include <signal.h>
#include <thread>
#include "mqtt/async_client.h"

const std::string SERVER_ADDRESS("tcp://k8a206.p.ssafy.io:3333");
const std::string CLIENT_ID("1");
const std::string TOPIC("test/" + CLIENT_ID);
const int QOS = 1;
volatile sig_atomic_t is_running = 1;

void sigint_handler(int signal) {
    std::cout << "Caught signal " << signal << std::endl;
    is_running = 0;
}

class callback : public virtual mqtt::callback {
public:
    void connection_lost(const std::string& cause) override {
        std::cout << "Connection lost: " << cause << std::endl;
    }
    
    void message_arrived(mqtt::const_message_ptr msg) override {
        std::cout << "Message arrived on topic '" << msg->get_topic() << "': " << msg->to_string() << std::endl;
    }

    void delivery_complete(mqtt::delivery_token_ptr token) override {
        1;
        //std::cout << "Delivery complete for token: " << token->get_message_id() << std::endl;
    }
};

void publish(mqtt::async_client& client) {
    int count = 0;

    while (true) {
        std::string payload = "";
        std::cin >> payload;
        mqtt::message_ptr pubmsg = mqtt::make_message(TOPIC, payload);
        pubmsg->set_qos(QOS);

        try {
            mqtt::token_ptr pubtok = client.publish(pubmsg);
            pubtok->wait();
        }
        catch (const mqtt::exception& exc) {
            std::cerr << "Error: " << exc.what() << std::endl;
        }
        std::this_thread::sleep_for(std::chrono::seconds(DELAY_INTERVAL_SECONDS));
    }
}

void subscribe(mqtt::async_client& client)
{
    std::cout << "Subscribing to topic '" << TOPIC << "'..." << std::endl;
    try {
        mqtt::token_ptr subtok = client.subscribe(TOPIC, QOS);
        subtok->wait();
        std::cout << "Subscribed." << std::endl;
    }
    catch (const mqtt::exception& exc) {
        std::cerr << "Error: " << exc.what() << std::endl;
        return;
    }
    while (is_running) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}


int main(int argc, char* argv[]) {

    // 강제종료(ctrl + C) 시그널 등록
    signal(SIGINT, sigint_handler);
    
    // Create MQTT client instance
    mqtt::async_client client(SERVER_ADDRESS, CLIENT_ID);

    // Set callback functions
    callback cb;
    client.set_callback(cb);

    // Connect to MQTT broker
    mqtt::connect_options connOpts;
    connOpts.set_clean_session(true);
    std::cout << "Connecting to the MQTT server..." << std::endl;
    try {
        mqtt::token_ptr conntok = client.connect(connOpts);
        conntok->wait();
        std::cout << "Connected." << std::endl;
    }
    catch (const mqtt::exception& exc) {
        std::cerr << "Error: " << exc.what() << std::endl;
        return 1;
    }

    // Start thread
    std::thread subscribe_thread(subscribe, std::ref(client));
    std::thread publish_thread(publish, std::ref(client));
    
    while (is_running) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    publish_thread.join();
    subscribe_thread.join();

    // 구독 해지
    mqtt::token_ptr unsubtok = client.unsubscribe(TOPIC);
    unsubtok->wait();
    std::cout << "Unsubscribed." << std::endl;

    // Disconnect from MQTT broker
    mqtt::token_ptr disctok = client.disconnect();
    disctok->wait();

    return 0;
}


