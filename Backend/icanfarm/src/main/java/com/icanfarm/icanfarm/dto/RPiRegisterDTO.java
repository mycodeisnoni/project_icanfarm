package com.icanfarm.icanfarm.dto;

import lombok.Getter;

@Getter
public class RPiRegisterDTO {
    private Long memberId;
    private boolean tempModule;
    private boolean humidModule;
    private boolean lightModule;
    private boolean fanModule;
    private boolean co2Module;
}
