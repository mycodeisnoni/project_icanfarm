#include "thread.h"
#include <iostream>

Thread::Thread(QObject* parent, mqtt::async_client* mqtt_client, const std::string& topic) :
    QThread(parent),
    mqtt_client_(mqtt_client),
    topic_(topic)
{

}

void Thread::run()
{
      std::cout << "Subscribing to topic 'test/1'..." << std::endl;
      try {
          mqtt::token_ptr subtok = mqtt_client_->subscribe("test/1", 1);
          subtok->wait();
          std::cout << "Subscribed." << std::endl;
      }
      catch (const mqtt::exception& exc) {
          std::cerr << "Error: " << exc.what() << std::endl;
      }
      
}

void Thread::run_pub()
{
    while(1){
          std::cout << "Publishing to topic 'test/1'..." << std::endl;
          mqtt::message_ptr pubmsg = mqtt::make_message("test/1", "olla");
          pubmsg->set_qos(1);
    
        try {
            mqtt::token_ptr pubtok = mqtt_client_->publish(pubmsg);
            pubtok->wait();
        }
        catch (const mqtt::exception& exc) {
            std::cerr << "Error: " << exc.what() << std::endl;
        }
    }
      
}

