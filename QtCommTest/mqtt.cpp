#include "mqtt.h"

void MqttCallback::connection_lost(const std::string &cause)
{
    std::cout << "Connection lost: " << cause << std::endl;
}

void MqttCallback::message_arrived(mqtt::const_message_ptr msg)
{
    std::string topic = msg->get_topic();
    std::string data = msg->to_string();
    std::cout << "'" << topic << "' : " << data << std::endl;
}
