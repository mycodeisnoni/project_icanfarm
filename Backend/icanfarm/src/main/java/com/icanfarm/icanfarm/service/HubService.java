package com.icanfarm.icanfarm.service;

import com.icanfarm.icanfarm.dto.InfoValueDTO;
import com.icanfarm.icanfarm.dto.LightSettingDTO;
import com.icanfarm.icanfarm.dto.SettingValueDTO;
import com.icanfarm.icanfarm.entity.FarmSensor;
import com.icanfarm.icanfarm.entity.Hub;
import com.icanfarm.icanfarm.exception.HubNotExistException;
import com.icanfarm.icanfarm.repository.FarmSensorRepository;
import com.icanfarm.icanfarm.repository.HubRepository;
import lombok.RequiredArgsConstructor;
import org.springframework.stereotype.Service;

import java.time.LocalDateTime;
import java.time.temporal.ChronoUnit;
import java.util.List;
import java.util.Optional;
import java.util.stream.Collectors;

@Service
@RequiredArgsConstructor
public class HubService {
    private final HubRepository hubRepository;
    private final FarmSensorRepository farmSensorRepository;

    private Hub getHub(Long id){
        Optional<Hub> hubOpt = hubRepository.findById(id);

        if(hubOpt.isEmpty())
            throw new HubNotExistException();

        return hubOpt.get();
    }

    public SettingValueDTO getTempSettings(Long id) {
        Hub hub = getHub(id);

        return SettingValueDTO.builder()
                .maxValue(hub.getTempSetting())
                .minValue(hub.getTempRate())
                .build();
    }

    public void setTempSetting(Long id, SettingValueDTO settingValueDTO) {
        Hub hub = getHub(id);

        hub.changeTempSettings(settingValueDTO.getMaxValue(), settingValueDTO.getMinValue());
        hubRepository.save(hub);
    }

    public SettingValueDTO getHumidSetting(Long id) {
        Hub hub = getHub(id);

        return SettingValueDTO.builder()
                .maxValue(hub.getHumidSetting())
                .minValue(hub.getHumidRate())
                .build();
    }

    public void setHumidSetting(Long id, SettingValueDTO settingValueDTO) {
        Hub hub = getHub(id);

        hub.changeHumidSettings(settingValueDTO.getMaxValue(), settingValueDTO.getMinValue());
        hubRepository.save(hub);
    }

    public LightSettingDTO getLightSetting(Long id) {
        Hub hub = getHub(id);

        return LightSettingDTO.builder()
                .startTime(hub.getLightTurnOnTime())
                .endTime(hub.getLightTurnOffTime())
                .build();
    }

    public void setLightSetting(Long id, LightSettingDTO lightSettingDTO) {
        Hub hub = getHub(id);

        hub.changeLightSettings(lightSettingDTO.getStartTime(), lightSettingDTO.getEndTime());
        hubRepository.save(hub);
    }

    public List<InfoValueDTO> getTempInfo(String sensor, Long id) {
        LocalDateTime end = LocalDateTime.now();
        LocalDateTime start = end.minus(7, ChronoUnit.DAYS);

        List<FarmSensor> sensors = farmSensorRepository.findFarmSensorsByNameAndHubId(sensor, id, start, end);
        return sensors.stream().map(
                s -> InfoValueDTO.builder()
                        .date(s.getDate())
                        .value(s.getValue())
                        .build()
        ).collect(Collectors.toList());
    }

    public String getHubInfo(Long hubId) throws Exception{
        Hub hub = getHub(hubId);
        return hub.getInitialInfoJson();
    }

    public String getHubPasswd(Long hubId){
        Hub hub = getHub(hubId);
        return hub.getMember().getPasswd();
    }

    public void changeHubSensorSetting(Long hubId, String name, Double value) {
        Hub hub = getHub(hubId);
        if(name.equals("temp")){
            hub.changeTempSettings(value, hub.getTempRate());
        }else if(name.equals("humid")){
            hub.changeHumidSettings(value, hub.getHumidRate());
        }
        hubRepository.save(hub);
    }
}
