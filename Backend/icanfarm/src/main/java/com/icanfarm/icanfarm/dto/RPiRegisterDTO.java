package com.icanfarm.icanfarm.dto;

import lombok.AllArgsConstructor;
import lombok.Builder;
import lombok.Getter;
import lombok.NoArgsConstructor;

@Getter
@NoArgsConstructor
public class RPiRegisterDTO {
    private Long memberId;
    private boolean tempModule;
    private boolean humidModule;
    private boolean lightModule;
    private boolean fanModule;
    private boolean co2Module;

    @Builder
    public RPiRegisterDTO(Long memberId, boolean tempModule, boolean humidModule, boolean lightModule, boolean fanModule, boolean co2Module){
        this.memberId = memberId;
        this.tempModule = tempModule;
        this.humidModule = humidModule;
        this.lightModule = lightModule;
        this.fanModule = fanModule;
        this.co2Module = co2Module;
    }
}
