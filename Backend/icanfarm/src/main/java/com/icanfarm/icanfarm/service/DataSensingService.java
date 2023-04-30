package com.icanfarm.icanfarm.service;

import com.icanfarm.icanfarm.config.MqttConfig;
import com.icanfarm.icanfarm.entity.FarmSensor;
import com.icanfarm.icanfarm.repository.FarmSensorRepository;
import lombok.RequiredArgsConstructor;
import org.springframework.stereotype.Service;

@Service
@RequiredArgsConstructor
public class DataSensingService {
    private final FarmSensorRepository farmSensorRepository;
    private final MqttConfig.OutboundGateway outboundGateway;
    private final HubService hubService;

    public void saveSensorData(Long hubId, String name, Double value) {
        FarmSensor farmSensor = FarmSensor.builder()
                .hubId(hubId)
                .name(name)
                .value(value)
                .build();

        farmSensorRepository.save(farmSensor);
    }

    public void sendSensorData(Long hubId) {
        try{
            outboundGateway.sendToMqtt(hubService.getHubInfo(hubId), MqttConfig.OutboundGateway.INITIAL_TOPIC + hubId.toString());
            outboundGateway.sendToMqtt(hubService.getHubPasswd(hubId), MqttConfig.OutboundGateway.PASSWORD_TOPIC + hubId);
        }catch (Exception e){
            e.printStackTrace();
        }
    }

    public void sendHubPasswod(Long hubId) {
        try{
            outboundGateway.sendToMqtt(hubService.getHubPasswd(hubId), MqttConfig.OutboundGateway.PASSWORD_TOPIC + hubId);
        }catch (Exception e){
            e.printStackTrace();
        }
    }

    public void sendHubPasswod(String passwd, Long hubId) {
        try{
            outboundGateway.sendToMqtt(passwd, MqttConfig.OutboundGateway.PASSWORD_TOPIC + hubId);
        }catch (Exception e){
            e.printStackTrace();
        }
    }

    public void changeSensorTarget(String name, Long hubId, Double value) {
        try{
            outboundGateway.sendToMqtt(value.toString(), "server/"+ name + "/target/" + hubId);
        }catch(Exception e){
            e.printStackTrace();
        }
    }

    public void changeSensorRange(String name, Long hubId, Double value) {
        try{
            outboundGateway.sendToMqtt(value.toString(),  "server/" + name + "/range/" + hubId);
        }catch(Exception e){
            e.printStackTrace();
        }
    }

    public void saveSensorTargetValue(Long hubId, String name, Double value) {
        hubService.setSensorTarget(name, hubId, value);
    }

    public void saveSensorRnageValue(Long hubId, String name, Double value) {
        hubService.setSensorRange(name, hubId, value);
    }
}
