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

        mqtt_client_->start_consuming(); // �޽��� ���� ���
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
        if (serial_port_->waitForReadyRead(1000)) // 1�� ���� �����͸� ��ٸ��ϴ�.
        {
            QString s = serial_port_->readAll(); // ���� ��� ������ �޽��ϴ�.
            std::string recv = s.toUtf8().constData();
            std::cout << "received message : " << recv << std::endl;

            // 1) ���� ������ ������ ����
            

            // 2) ���ð��� �� ������ ���� ��� ����
            if (recv == "test\n")
            {
                // �������� �ϴ� �����͸� �ۼ��մϴ�.
                QByteArray data = "Hello, world!\n";
                // �����͸� �ø��� ��Ʈ�� �����մϴ�.
                qint64 bytesWritten = serial_port_->write(data);
                if (bytesWritten == -1)
                {
                    qDebug() << "Failed to write the data to serial port";
                }
                else
                {
                    // ���� ������ �����͸� �ø��� ��Ʈ�� �����ϴ�.
                    serial_port_->flush();
                    std::cout << "Data send success" << std::endl;
                }
            }

            // 3) ��� ���� �Ѿ �� ��� �޽��� ����

        }
    }
}
