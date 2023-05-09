
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <cstring>
#include <iostream>
#include <chrono>
#include <thread>
#include "mqtt/async_client.h"
#include <QtMqtt/QMqttClient>
#include <QtMqtt/QMqttMessage>
#include <QtMqtt/QMqttSubscription>
#include "ui_mainwindow.h"
#include "thread.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    
    //mqtt::callback cb;
    //mqtt::connect_options connOpts;

private:
    Ui::MainWindow *ui;
    mqtt::async_client client;
    

private slots:
    void subscribe_btn();
    void onMessageArrived(QString message);
};

#endif // MAINWINDOW_H
