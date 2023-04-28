package com.icanfarm.icanfarm.dto;

import lombok.*;

@Getter
@Setter
@NoArgsConstructor
public class SettingValueDTO {
    private Double maxValue;
    private Double minValue;

    @Builder
    public SettingValueDTO(Double maxValue, Double minValue){
        this.maxValue = maxValue;
        this.minValue = minValue;
    }
}
