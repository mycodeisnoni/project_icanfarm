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
            outboundGateway.sendToMqtt(hubService.getHubInfo(hubId), "test");
            outboundGateway.sendToMqtt(hubService.getHubPasswd(hubId), "test");
        }catch (Exception e){
            e.printStackTrace();
        }
    }

    public void sendHubPasswod(long hubId) {
        try{
            outboundGateway.sendToMqtt(hubService.getHubPasswd(hubId), "test");
        }catch (Exception e){
            e.printStackTrace();
        }
    }

    public void saveSensorSetting(Long hubId, String name, Double value) {
        hubService.changeHubSensorSetting(hubId, name, value);
    }
}
