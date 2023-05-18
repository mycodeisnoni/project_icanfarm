package com.icanfarm.icanfarm.config;

import com.icanfarm.icanfarm.service.DataSensingService;
import lombok.RequiredArgsConstructor;
import org.eclipse.paho.client.mqttv3.MqttAsyncClient;
import org.eclipse.paho.client.mqttv3.MqttConnectOptions;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.integration.annotation.MessagingGateway;
import org.springframework.integration.annotation.ServiceActivator;
import org.springframework.integration.channel.DirectChannel;
import org.springframework.integration.core.MessageProducer;
import org.springframework.integration.mqtt.core.DefaultMqttPahoClientFactory;
import org.springframework.integration.mqtt.inbound.MqttPahoMessageDrivenChannelAdapter;
import org.springframework.integration.mqtt.outbound.MqttPahoMessageHandler;
import org.springframework.integration.mqtt.support.DefaultPahoMessageConverter;
import org.springframework.integration.mqtt.support.MqttHeaders;
import org.springframework.messaging.MessageChannel;
import org.springframework.messaging.MessageHandler;
import org.springframework.messaging.handler.annotation.Header;

@Configuration
@RequiredArgsConstructor
public class MqttConfig {

    private final DataSensingService dataSensingService;
    private static String MQTT_USERNAME = "web_server";
    private static String MQTT_PASSWORD = "1234";

    private static String MQTT_CLIENT_ID = MqttAsyncClient.generateClientId();
    private static String TOPIC_TEMP = "rpi/temp/#";
    private static String TOPIC_HUMID = "rpi/humid/#";
    private static String TOPIC_CO2 = "rpi/co2/#";
    private static String TOPIC_ADMIN = "rpi/admin/#";
    private static String BROKER_URL = "tcp://k8a206.p.ssafy.io:3333";
    private static String[] URLS = {BROKER_URL};

    private MqttConnectOptions connectOptions(){
        MqttConnectOptions options = new MqttConnectOptions();

        options.setCleanSession(true);
        options.setUserName(MQTT_USERNAME);
        options.setPassword(MQTT_PASSWORD.toCharArray());
        options.setServerURIs(URLS);
        return options;
    }

    @Bean
    public DefaultMqttPahoClientFactory defaultMqttPahoClientFactory(){
        DefaultMqttPahoClientFactory clientFactory = new DefaultMqttPahoClientFactory();
        clientFactory.setConnectionOptions(connectOptions());
        return clientFactory;
    }


    @Bean
    public MessageChannel mqttInputChannel() {
        return new DirectChannel();
    }

    @Bean
    public MessageProducer inboundChannel() {
        MqttPahoMessageDrivenChannelAdapter adapter =
                new MqttPahoMessageDrivenChannelAdapter(BROKER_URL, MQTT_CLIENT_ID, TOPIC_TEMP, TOPIC_HUMID, TOPIC_CO2, TOPIC_ADMIN);
        adapter.setCompletionTimeout(5000);
        adapter.setConverter(new DefaultPahoMessageConverter());
        adapter.setQos(1);
        adapter.setOutputChannel(mqttInputChannel());
        return adapter;
    }

    @Bean
    @ServiceActivator(inputChannel = "mqttInputChannel")
    public MessageHandler inboundMessageHandler() {
        return message -> {
            String topic = (String) message.getHeaders().get(MqttHeaders.RECEIVED_TOPIC);

            System.out.println("!!!!! Topic:" + topic);
            System.out.println("!!!!! Payload" + message.getPayload());
            String[] subTopics = topic.split("/");
            if(subTopics[1].equals("admin")){
                if(subTopics[2].equals("power")){
                    dataSensingService.sendSensorData(Long.parseLong(subTopics[3]));
                }else{
                    dataSensingService.sendHubPasswod(Long.parseLong(subTopics[3]));
                }
            }else{
                if(subTopics[2].equals("data")){
                    dataSensingService.saveSensorData(Long.parseLong(subTopics[3]), subTopics[1], Double.parseDouble((String)message.getPayload()));
                }else if(subTopics[2].equals("set")){
                    dataSensingService.saveSensorTargetValue(Long.parseLong(subTopics[3]), subTopics[1], Double.parseDouble((String)message.getPayload()));
                }else if(subTopics[2].equals("range")){
                    dataSensingService.saveSensorRangeValue(Long.parseLong(subTopics[3]), subTopics[1], Double.parseDouble((String)message.getPayload()));
                }
            }
        };
    }

    @Bean
    public MessageChannel mqttOutboundChannel() {
        return new DirectChannel();
    }

    @Bean
    @ServiceActivator(inputChannel = "mqttOutboundChannel")
    public MessageHandler mqttOutbound(DefaultMqttPahoClientFactory clientFactory) {
        MqttPahoMessageHandler messageHandler =
                new MqttPahoMessageHandler(MQTT_CLIENT_ID, clientFactory);
        messageHandler.setAsync(true);
        messageHandler.setDefaultQos(1);
        return messageHandler;
    }

    @MessagingGateway(defaultRequestChannel = "mqttOutboundChannel")
    public interface OutboundGateway {
        static final String INITIAL_TOPIC = "server/admin/power/";
        static final String PASSWORD_TOPIC = "server/admin/password/";

        void sendToMqtt(String payload, @Header(MqttHeaders.TOPIC) String topic);
    }
}
