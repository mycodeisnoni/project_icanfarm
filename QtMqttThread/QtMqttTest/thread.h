#ifndef THREAD_H
#define THREAD_H

#include <QThread>
#include <QtDebug>
#include <mqtt/async_client.h>

class Thread : public QThread
{
    Q_OBJECT

public:
    explicit Thread(QObject *parent = 0);
     Thread(QObject* parent, mqtt::async_client* mqtt_client, const std::string& topic);
     void run_pub();

private:
    void run();
    mqtt::async_client* mqtt_client_;
    std::string topic_;
};
#endif // THREAD_H
