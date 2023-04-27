#include <iostream>
#include <cstring>
#include <chrono>
#include <thread>
#include "mqtt/async_client.h"

const std::string SERVER_ADDRESS("tcp://k8a206.p.ssafy.io:3333");
const std::string CLIENT_ID("RPi-publish");
const std::string TOPIC("test");
const int QOS = 1;
const int DELAY_INTERVAL_SECONDS = 1;

class callback : public virtual mqtt::callback,
    public virtual mqtt::iaction_listener {
public:
    void connection_lost(const std::string& cause) override {
        std::cout << "Connection lost: " << cause << std::endl;
    }

    void delivery_complete(mqtt::delivery_token_ptr token) override {
        std::cout << "Delivery complete for token: " << token->get_message_id() << std::endl;
    }

    void on_failure(const mqtt::token& tok) override {
        std::cout << "Failure: " << tok.get_message_id() << std::endl;
    }

    void on_success(const mqtt::token& tok) override {
        std::cout << "Success: " << tok.get_message_id() << std::endl;
    }
};

int main(int argc, char* argv[]) {
    mqtt::async_client client(SERVER_ADDRESS, CLIENT_ID);
    callback cb;
    client.set_callback(cb);

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

//        std::this_thread::sleep_for(std::chrono::seconds(DELAY_INTERVAL_SECONDS));
    }

    return 0;
}

