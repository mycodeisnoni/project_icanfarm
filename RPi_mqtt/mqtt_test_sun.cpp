#include <iostream>
#include <cstdlib>
#include <cstring>
#include "mqtt/async_client.h"

const std::string SERVER_ADDRESS("tcp://k8a206.p.ssafy.io:3333");
const std::string CLIENT_ID("raspberry-pi-client");

class mqtt_callback : public virtual mqtt::callback {
public:
    virtual void connection_lost(const std::string& cause) {
        std::cout << "Connection lost: " << cause << std::endl;
    }

    virtual void message_arrived(mqtt::const_message_ptr msg) {
        std::cout << "Message arrived: " << msg->get_topic() << " -> " << msg->to_string() << std::endl;
    }

    virtual void delivery_complete(mqtt::delivery_token_ptr token) {}
};

int main(int argc, char* argv[]) {
    mqtt::async_client client(SERVER_ADDRESS, CLIENT_ID);
    mqtt_callback cb;
    client.set_callback(cb);

    mqtt::connect_options options;
    options.set_clean_session(true);

    try {
        std::cout << "Connecting to MQTT server..." << std::endl;
        mqtt::token_ptr conntok = client.connect(options);
        conntok->wait();
        std::cout << "Connected." << std::endl;
        int k = 0;
        while (k<5) {
            std::string topic = "test";
            std::string payload = "This is temp";
            std::string payload2 = "This is humid";
            int qos = 0;
            bool retained = false;
            k++;
            std::cout << "Publishing message: " << payload << std::endl;
            mqtt::message_ptr pubmsg = mqtt::make_message(topic, payload, qos, retained);
            mqtt::token_ptr pubtok = client.publish(pubmsg);
            mqtt::message_ptr pubmsg2 = mqtt::make_message(topic, payload2, qos, retained);
            mqtt::token_ptr pubtok2 = client.publish(pubmsg2);
            pubtok->wait();
            pubtok2->wait();
        }
        std::cout << "Disconnecting from MQTT server..." << std::endl;
        mqtt::token_ptr disconntok = client.disconnect();
        disconntok->wait();
        std::cout << "Disconnected." << std::endl;
    }
    catch (const mqtt::exception& exc) {
        std::cerr << "Error: " << exc.what() << std::endl;
        return 1;
    }

    return 0;
}
