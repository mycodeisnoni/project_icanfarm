#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QPalette>
#include <cstring>
#include <iostream>
#include <chrono>
#include <thread>
#include "ui_mainwindow.h"
#include <unistd.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <linux/can.h>
#include <linux/can/raw.h>
#include "thread.h"
#include "mqtt.h"
#include "login_dialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow* ui;
    login_dialog* login_D; // login dialog
    mqtt::async_client client;
    Thread* recvMqttFromServer_t;
    Thread* sensorDataProcess_t;

private slots:
    void upTemperature();
    void downTemperature();
    void downHumid();
    void upHumid();
    void upCo2();
    void downCo2();
    void goLogout();
    void changeWaterColor();
    void changeWindColor();
    void changeSunColor();
    void changeCloudColor();
    void changeValue();
    void recvLogInResult(int flag); // 로그인 결과에 따라 login_diglog로부터 값 수신
    void sendMqtt2Server(const std::string topic, const std::string msg); // 서버로 MQTT 전송
};

#endif // MAINWINDOW_H
