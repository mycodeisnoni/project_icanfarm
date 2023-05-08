
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

private slots:
    void subscribe_btn();
};

#endif // MAINWINDOW_H
