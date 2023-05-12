#ifndef THREAD_H
#define THREAD_H

#include <QThread>
#include <QtDebug>
#include <mqtt/async_client.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <linux/can.h>
#include <linux/can/raw.h>

class Thread : public QThread
{
    Q_OBJECT

public:
    Thread(QObject* parent, mqtt::async_client* mqtt_client, struct can_frame* frame, int sock, int num);

private:
    void run() override;
    mqtt::async_client* mqtt_client_;
    struct can_frame* frame_;
    int sock_;
    int num_;
    
signals:
    void applyServerChange(int flag);
};

#endif // THREAD_H
