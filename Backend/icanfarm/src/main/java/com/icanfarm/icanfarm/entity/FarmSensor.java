package com.icanfarm.icanfarm.entity;

import org.springframework.data.annotation.Id;

import java.time.LocalDateTime;

public class FarmSensor {

    @Id
    private String id;

    private String channel;
    private Double value;
    private LocalDateTime date;

}
