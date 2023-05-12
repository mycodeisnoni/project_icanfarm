#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QDebug"
#include <string>

// CAN communication variables
int sock;
struct sockaddr_can addr;
struct can_frame frame;
struct ifreq ifr;

// Create MQTT client instance
const std::string MQTT_SERVER_ADDRESS = "tcp://k8a206.p.ssafy.io:3333";
const std::string CLIENT_ID = "1";
mqtt::async_client client(MQTT_SERVER_ADDRESS, CLIENT_ID);
MqttCallback cb;
mqtt::connect_options connOpts;

// Mainwindow 생성자
MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent),
                                          ui(new Ui::MainWindow),
                                          client("tcp://k8a206.p.ssafy.io:3333", "1")
{
    ui->setupUi(this);

    // Set up MQTT client options
    mqtt::connect_options connOpts;
    connOpts.set_keep_alive_interval(20);
    client.set_callback(cb);
    connOpts.set_clean_session(true);

    std::cout << "Connecting to the MQTT server..." << std::endl;
    try
    {
        mqtt::token_ptr conntok = client.connect(connOpts);
        conntok->wait();
        std::cout << "Connected." << std::endl;
    }
    catch (const mqtt::exception& exc)
    {
        std::cerr << "Error: " << exc.what() << std::endl;
    }

    // CAN 소켓 생성
    if ((sock = socket(PF_CAN, SOCK_RAW, CAN_RAW)) < 0)
    {
        perror("Error while creating socket");
    }

    strcpy(ifr.ifr_name, "vcan0");   // CAN 인터페이스 이름 설정
    ioctl(sock, SIOCGIFINDEX, &ifr); // 소켓-네트워크 인터페이스 연결

    // 소켓 주소 구조체 초기화
    addr.can_family = AF_CAN;
    addr.can_ifindex = ifr.ifr_ifindex;

    // 소켓에 주소 바인딩
    if (bind(sock, (struct sockaddr*)&addr, sizeof(addr)) < 0)
    {
        perror("Error in socket bind");
    }

    // 서버에 전원 ON 메시지 전송
    sendMqtt2Server("rpi/admin/power/1", "hi");

    Thread *recvMqttFromServer_t = new Thread(this, &client, NULL, 0, 0);
    Thread *sensorDataProcess_t = new Thread(this, &client, &frame, sock, 1);

    recvMqttFromServer_t->start();
    sensorDataProcess_t->start();
}

// 소멸자
MainWindow::~MainWindow()
{
    mqtt::token_ptr unsubtok = client.unsubscribe("test/1");
    unsubtok->wait();

    // Disconnect from the MQTT server
    mqtt::token_ptr disctok = client.disconnect();
    disctok->wait();

    // Delete dynamically allocated threads
    delete recvMqttFromServer_t;
    delete sensorDataProcess_t;

    delete ui;
}

// 기존에 수정된 값
// 만약 비밀번호 틀리면 기존에 수정된 값으로 다시 바꿔야 한다
double origin_Temp = 30.0;
double origin_Humid = 64.0;
int origin_Co2 = 400;

void MainWindow::upTemperature()
{
    double tmp = ui->temp_setting_text->text().toDouble() + 0.1;
    ui->temp_setting_text->setText(QString::number(tmp, 'g', 7));
}

void MainWindow::downTemperature()
{
    double tmp = ui->temp_setting_text->text().toDouble() - 0.1;
    ui->temp_setting_text->setText(QString::number(tmp, 'g', 7));
}

void MainWindow::upHumid()
{
    double tmp = ui->humid_setting_text->text().toDouble() + 0.1;
    ui->humid_setting_text->setText(QString::number(tmp, 'g', 7));
}

void MainWindow::downHumid()
{
    double tmp = ui->humid_setting_text->text().toDouble() - 0.1;
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

void MainWindow::changeValue() // 변경 버튼 눌렀을 때
{
    login_D = new login_dialog;

    // login_dialog의 signal과 mainwindow의 slot 연결
    connect(login_D, SIGNAL(sendSensorValue(int)), this, SLOT(receiveSensorValue(int)));

    login_D->setModal(true); // modal로 열어야 로그인 창 열려있을 때 메인 창 건드리지 못 함
    login_D->exec();
}

// login_dialog로부터 값 받으면 기존의 값으로 바꿀 건지
// flag == 1이면 값 변경
// flag == -1이면 값 변경 X
void MainWindow::receiveSensorValue(int flag)
{
    qDebug() << flag;

    if (flag == 1) // 값 변경됨
    {
        double new_Temp = ui->temp_setting_text->text().toDouble();
        if (origin_Temp != new_Temp)
        {
            origin_Temp = new_Temp;
            sendMqtt2Server("rpi/temp/set/1", ui->temp_setting_text->text().toStdString());
            qDebug() << "set TEMP changed to " << ui->temp_setting_text->text().toStdString().c_str();
        }

        double new_Humid = ui->humid_setting_text->text().toDouble();
        if (origin_Humid != new_Humid)
        {
            origin_Humid = new_Humid;
            sendMqtt2Server("rpi/humid/set/1", ui->humid_setting_text->text().toStdString());
            qDebug() << "set HUMID changed to " << ui->humid_setting_text->text().toStdString().c_str();
        }

        origin_Co2 = ui->co2_setting_text->text().toInt();
    }
    else // 값 변경 X, 기존 값으로 돌려놓기
    {
        ui->temp_setting_text->setText(QString::number(origin_Temp, 'g', 7));
        ui->humid_setting_text->setText(QString::number(origin_Humid, 'g', 7));
        ui->co2_setting_text->setText(QString::number(origin_Co2));
    }
}

void MainWindow::sendMqtt2Server(const std::string topic, const std::string msg)
{
    mqtt::message_ptr pubmsg = mqtt::make_message(topic, msg);
    pubmsg->set_qos(1);

    try
    {
        mqtt::token_ptr pubtok = client.publish(pubmsg);
        pubtok->wait();
    }
    catch (const mqtt::exception& exc)
    {
        std::cerr << "Error: " << exc.what() << std::endl;
    }
}
