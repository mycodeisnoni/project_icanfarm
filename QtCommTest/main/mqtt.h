#ifndef MQTT_H
#define MQTT_H

#include <QObject>
#include <iostream>
#include <string>
#include "mqtt/async_client.h"

extern const std::string CLIENT_ID;
extern mqtt::async_client client;
extern mqtt::connect_options connOpts;

class MqttCallback :public QObject, public mqtt::callback
{
	Q_OBJECT
public:
    //explicit MqttCallback(QObject* parent = nullptr);
    void connection_lost(const std::string& cause) override;
    void message_arrived(mqtt::const_message_ptr msg) override;

signals:
    void sendServertemp(double t);
    void sendServerhumid(double h);
    void sendServerCo2(int co);
};


#endif // MQTT_H
