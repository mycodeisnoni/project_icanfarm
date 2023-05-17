#ifndef THREAD_H
#define THREAD_H

#include <QThread>
#include <QtDebug>
#include <mqtt/async_client.h>
#include <QtSerialPort/QSerialPort>

class Thread : public QThread
{
    Q_OBJECT

public:
    Thread(QObject* parent, mqtt::async_client* mqtt_client, QSerialPort* serial_port, int num);

private:
    void run() override;
    mqtt::async_client* mqtt_client_;
    QSerialPort* serial_port_;
    int num_;
};

#endif // THREAD_H
