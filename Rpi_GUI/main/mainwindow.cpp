
#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::upTemperature()
{
    double tmp = ui->temp_setting_text->text().toDouble() + 0.2;
    ui->temp_setting_text->setText(QString::number(tmp, 'g', 7));
}

void MainWindow::downTemperature()
{
    double tmp = ui->temp_setting_text->text().toDouble() - 0.2;
    ui->temp_setting_text->setText(QString::number(tmp, 'g', 7));
}

void MainWindow::upHumid()
{
    double tmp = ui->humid_setting_text->text().toDouble() + 0.2;
    ui->humid_setting_text->setText(QString::number(tmp, 'g', 7));
}

void MainWindow::downHumid()
{
    double tmp = ui->humid_setting_text->text().toDouble() - 0.2;
    ui->humid_setting_text->setText(QString::number(tmp, 'g', 7));
}
void MainWindow::upCo2()
{
    int tmp = ui->co2_setting_text->text().toInt() + 1;
    ui->co2_setting_text->setText(QString::number(tmp));
}

void MainWindow::downCo2()
{
    int tmp = ui->co2_setting_text->text().toInt() - 1;
    ui->co2_setting_text->setText(QString::number(tmp));
}
void MainWindow::goLogout() // logout 함수
{
    QMessageBox msgBox;
    msgBox.setText("창 닫습니다요~~~~~~!!!");
    msgBox.exec();
    QWidget::close(); // 창 닫기
}

// 우측 센서 패널 색 바꾸기
QString color_arr[] = {"background-color: rgb(61, 91, 101);", "background-color: rgb(255, 255, 0);", "background-color: rgb(255, 0, 255);"};
int water_point = 0;
int wind_point = 0;
int sun_point = 0;
int cloud_point = 0;
void MainWindow::changeWaterColor() // 누르면 색 바뀌도록
{
    water_point = (water_point + 1) % 3;
    ui->show_water->setStyleSheet(color_arr[water_point]);
}
void MainWindow::changeWindColor() // 누르면 색 바뀌도록
{
    wind_point = (wind_point + 1) % 3;
    ui->show_wind->setStyleSheet(color_arr[wind_point]);
}
void MainWindow::changeSunColor() // 누르면 색 바뀌도록
{
    sun_point = (sun_point + 1) % 3;
    ui->show_sun->setStyleSheet(color_arr[sun_point]);
}
void MainWindow::changeCloudColor() // 누르면 색 바뀌도록
{
    cloud_point = (cloud_point + 1) % 3;
    ui->show_co2->setStyleSheet(color_arr[cloud_point]);
}

