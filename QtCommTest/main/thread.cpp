#include "thread.h"
#include <iostream>

Thread::Thread(QObject* parent, mqtt::async_client* mqtt_client, struct can_frame* frame, int sock, int num) :
    QThread(parent),
    mqtt_client_(mqtt_client),
    frame_(frame),
    sock_(sock),
    num_(num)
{

}

void recvMqttFromServer(mqtt::async_client* mqtt_client_);
void sensorDataProcess(struct can_frame* frame_, int sock_, mqtt::async_client* mqtt_client_);

void Thread::run()
{
    std::cout << " Thread #" << num_ << " running" << std::endl;
    if (num_ == 0) recvMqttFromServer(mqtt_client_);
    else if (num_ == 1) sensorDataProcess(frame_, sock_, mqtt_client_);
}

void recvMqttFromServer(mqtt::async_client* mqtt_client_)
{
    std::cout << "Subscribing server..." << std::endl;
    try
    {
        mqtt::token_ptr subtok = mqtt_client_->subscribe("server/#", 1); // QOS = 1
        subtok->wait();
        std::cout << "Subscribed." << std::endl;
        
        mqtt_client_->start_consuming(); // 메시지 수신 대기
    }
    catch (const mqtt::exception& exc)
    {
        std::cerr << "Error: " << exc.what() << std::endl;
    }
}

void sensorDataProcess(struct can_frame* frame_, int sock_, mqtt::async_client* mqtt_client_)
{
    while (1)
    {
        std::cout << "DATA PROCESS ~\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
}
