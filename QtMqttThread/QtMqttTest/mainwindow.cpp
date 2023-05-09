#include "mainwindow.h"
#include "./ui_mainwindow.h"

class callback : public virtual mqtt::callback {
public:
    void connection_lost(const std::string& cause) override {
        std::cout << "Connection lost: " << cause << std::endl;
    }

    void message_arrived(mqtt::const_message_ptr msg) override {
        std::cout << "Message arrived on topic '" << msg->get_topic() << "': " << msg->to_string() << std::endl;
    }
};

// Create MQTT client instance
mqtt::async_client client("tcp://k8a206.p.ssafy.io:3333", "1");
callback cb;
mqtt::connect_options connOpts;


MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , client("tcp://k8a206.p.ssafy.io:3333", "1")
{
    ui->setupUi(this);

    // Set up MQTT client options
    mqtt::connect_options connOpts;
    connOpts.set_keep_alive_interval(20);
    client.set_callback(cb);
    connOpts.set_clean_session(true);

    std::cout << "Connecting to the MQTT server..." << std::endl;
    try {
        mqtt::token_ptr conntok = client.connect(connOpts);
        conntok->wait();
        std::cout << "Connected." << std::endl;
    }
    catch (const mqtt::exception& exc) {
        std::cerr << "Error: " << exc.what() << std::endl;
    }
    
    Thread* sub = new Thread(this, &client, "test/1");
    sub->start();
    Thread* pub = new Thread(this, &client, "test/1");
    pub->run_pub();

}

MainWindow::~MainWindow()
{
     mqtt::token_ptr unsubtok = client.unsubscribe("test/1");
    unsubtok->wait();

    // Disconnect from the MQTT server
    mqtt::token_ptr disctok = client.disconnect();
    disctok->wait();
    delete ui;
}

void MainWindow::onMessageArrived(QString message) {
    std::cout << "Message arrived: " << message.toStdString() << std::endl;
}


void MainWindow::subscribe_btn()
{
    QString s = ui->text->toPlainText();
    std::string send_s = s.toStdString();

    mqtt::message_ptr pubmsg = mqtt::make_message("test/1", send_s);
    pubmsg->set_qos(1);

    try {
        mqtt::token_ptr pubtok = client.publish(pubmsg);
        pubtok->wait();
    }
    catch (const mqtt::exception& exc) {
        std::cerr << "Error: " << exc.what() << std::endl;
    }


    QMessageBox msgBox;
    msgBox.setText(s);
    msgBox.exec();
}

