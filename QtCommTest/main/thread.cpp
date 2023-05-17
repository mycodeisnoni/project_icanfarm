#include "thread.h"
#include <iostream>

Thread::Thread(QObject* parent, mqtt::async_client* mqtt_client, QSerialPort* serial_port, int num) :
    QThread(parent),
    mqtt_client_(mqtt_client),
    serial_port_(serial_port),
    num_(num)
{

}

void recvMqttFromServer(mqtt::async_client* mqtt_client_);
void sensorDataProcess(mqtt::async_client* mqtt_client_, QSerialPort* serial_port_);

void Thread::run()
{
    std::cout << " Thread #" << num_ << " running" << std::endl;
    if (num_ == 0) recvMqttFromServer(mqtt_client_);
    else if (num_ == 1) sensorDataProcess(mqtt_client_, serial_port_);
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

void sensorDataProcess(mqtt::async_client* mqtt_client_, QSerialPort* serial_port_)
{
    while (1)
    {
        if (serial_port_->waitForReadyRead(1000)) // 1초 동안 데이터를 기다립니다.
        {
            QString s = serial_port_->readAll(); // 들어온 모든 데이터 받습니다.
            std::string recv = s.toUtf8().constData();
            std::cout << "received message : " << recv << std::endl;

            // 1) 받은 데이터 서버로 전송
            

            // 2) 세팅값에 안 맞으면 제어 명령 전송
            if (recv == "test\n")
            {
                // 보내고자 하는 데이터를 작성합니다.
                QByteArray data = "Hello, world!\n";
                // 데이터를 시리얼 포트로 전송합니다.
                qint64 bytesWritten = serial_port_->write(data);
                if (bytesWritten == -1)
                {
                    qDebug() << "Failed to write the data to serial port";
                }
                else
                {
                    // 내부 버퍼의 데이터를 시리얼 포트로 보냅니다.
                    serial_port_->flush();
                    std::cout << "Data send success" << std::endl;
                }
            }

            // 3) 허용 범위 넘어갈 시 경고 메시지 전송

        }
    }
}
