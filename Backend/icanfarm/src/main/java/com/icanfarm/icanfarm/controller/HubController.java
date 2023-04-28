package com.icanfarm.icanfarm.controller;

import com.icanfarm.icanfarm.dto.InfoValueDTO;
import com.icanfarm.icanfarm.dto.LightSettingDTO;
import com.icanfarm.icanfarm.dto.SettingValueDTO;
import com.icanfarm.icanfarm.service.HubService;
import lombok.RequiredArgsConstructor;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
@RequestMapping("/api")
@RequiredArgsConstructor
public class HubController {

    private final HubService hubService;

    @GetMapping("/{sensor}/{rpi_id}")
    public ResponseEntity getTempInfo(@PathVariable("sensor")String sensor, @PathVariable("rpi_id") Long id){
        List<InfoValueDTO> values = hubService.getTempInfo(sensor, id);
        return ResponseEntity.ok().body(values);
    }

    @GetMapping("/setting/temp/{rpi_id}")
    public ResponseEntity getTempSetting(@PathVariable("rpi_id") Long id){
        SettingValueDTO settingValueDTO = hubService.getTempSettings(id);
        return ResponseEntity.ok().body(settingValueDTO);
    }

    @PostMapping("/setting/temp/{rpi_id}")
    public ResponseEntity setTempSetting(@PathVariable("rpi_id") Long id, @RequestBody SettingValueDTO settingValueDTO){
        hubService.setTempSetting(id, settingValueDTO);
        return ResponseEntity.ok().body("온도 설정을 변경했습니다.");
    }

    @GetMapping("/setting/humid/{rpi_id}")
    public ResponseEntity getHumidSetting(@PathVariable("rpi_id") Long id){
        return ResponseEntity.ok().body(hubService.getHumidSetting(id));
    }

    @PostMapping("/setting/humid/{rpi_id}")
    public ResponseEntity setHumidSetting(@PathVariable("rpi_id") Long id, @RequestBody SettingValueDTO settingValueDTO){
        hubService.setHumidSetting(id, settingValueDTO);
        return ResponseEntity.ok().body("습도 설정을 변경했습니다.");
    }

    @GetMapping("/setting/light/{rpi_id}")
    public ResponseEntity getLightSetting(@PathVariable("rpi_id") Long id){
        return ResponseEntity.ok().body(hubService.getLightSetting(id));
    }

    @PostMapping("/setting/light/{rpi_id}")
    public ResponseEntity setLightSetting(@PathVariable("rpi_id") Long id, @RequestBody LightSettingDTO lightSettingDTO){
        hubService.setLightSetting(id, lightSettingDTO);
        return ResponseEntity.ok().body("조명 설정을 변경했습니다.");
    }
}
