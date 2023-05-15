#ifndef MQTT_H
#define MQTT_H

#include <iostream>
#include <string>
#include "mqtt/async_client.h"

extern const std::string CLIENT_ID;
extern mqtt::async_client client;
extern mqtt::connect_options connOpts;

class MqttCallback :public virtual mqtt::callback
{
public:
    void connection_lost(const std::string& cause) override;
    void message_arrived(mqtt::const_message_ptr msg) override;
};

#endif // MQTT_H
