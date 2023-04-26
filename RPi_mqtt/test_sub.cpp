#include <iostream>
#include <cstring>
#include "mqtt/async_client.h"

const std::string ADDRESS{ "tcp://mqtt.example.com:1883" };
const std::string CLIENT_ID{ "mqtt_cpp_client" };
const std::string TOPIC{ "test/topic" };
const int QOS = 1;

class callback : public virtual mqtt::callback
{
public:
    void connection_lost(const std::string& cause) override
    {
        std::cout << "Connection lost: " << cause << std::endl;
    }

    void delivery_complete(mqtt::delivery_token_ptr token) override
    {
        std::cout << "Delivery complete for token: "
            << token->get_message_id() << std::endl;
    }

    void message_arrived(mqtt::const_message_ptr message) override
    {
        std::cout << "Message arrived on topic '"
            << message->get_topic() << "': "
            << message->to_string() << std::endl;
    }
};

void subscribe_loop(mqtt::async_client& client)
{
    while (true) {
        mqtt::token_ptr subtok = client.subscribe(TOPIC, QOS);
        subtok->wait();
        std::this_thread::sleep_for(std::chrono::seconds(5));
    }
}

int main(int argc, char* argv[])
{
    // Create MQTT client instance
    mqtt::async_client client(ADDRESS, CLIENT_ID);

    // Set callback functions
    callback cb;
    client.set_callback(cb);

    // Connect to MQTT broker
    mqtt::connect_options conn_opts;
    conn_opts.set_keep_alive_interval(60);
    conn_opts.set_clean_session(true);
    mqtt::token_ptr conntok = client.connect(conn_opts);
    conntok->wait();

    // Start subscribing to the topic continuously
    subscribe_loop(client);

    // Disconnect from MQTT broker
    mqtt::token_ptr disctok = client.disconnect();
    disctok->wait();

    return 0;
}
