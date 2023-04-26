package com.icanfarm.icanfarm.entity;

import lombok.Builder;
import lombok.Getter;
import lombok.NoArgsConstructor;
import org.hibernate.annotations.ColumnDefault;
import org.hibernate.annotations.DynamicInsert;

import javax.persistence.*;
import java.time.LocalDateTime;

@DynamicInsert
@Entity
@Getter
@NoArgsConstructor
public class Hub {

    @Id
    @GeneratedValue
    private Long id;

    @ManyToOne
    @JoinColumn(name = "member_id")
    private Member member;

    @Column(nullable = false, unique = true)
    private String serial;

    private String nickname;

    @Column(name = "temp_max")
    @ColumnDefault("0.0")
    private Double tempMax;

    @Column(name = "temp_min")
    @ColumnDefault("0.0")
    private Double tempMin;

    @Column(name = "humid_max")
    @ColumnDefault("0.0")
    private Double humidMax;

    @Column(name = "humid_min")
    @ColumnDefault("0.0")
    private Double humidMin;

    @Column(name = "co2_max")
    @ColumnDefault("0.0")
    private Double co2Max;

    @Column(name = "co2_min")
    @ColumnDefault("0.0")
    private Double co2Min;

    @Column(name = "light_turn_on")
    private LocalDateTime lightTurnOnTime;

    @Column(name = "light_turn_off")
    private LocalDateTime lightTurnOffTime;

    @Column(name = "default_hub")
    @ColumnDefault("false")
    private Boolean defaultHub;

    @Column(name = "is_temp")
    @ColumnDefault("false")
    private Boolean isTemp;

    @Column(name = "is_humid")
    @ColumnDefault("false")
    private Boolean isHumid;

    @Column(name = "is_co2")
    @ColumnDefault("false")
    private Boolean isCo2;

    @Column(name = "is_fan")
    @ColumnDefault("false")
    private Boolean isFan;

    @Column(name = "is_light")
    @ColumnDefault("false")
    private Boolean isLight;

    @Column(name = "join_date")
    @ColumnDefault("'2000-01-01 00:00:00'")
    private LocalDateTime joinDate;

    public void registerMember(Member member, int cnt){
        this.member = member;
        this.nickname = "hub" + cnt;
        this.joinDate = LocalDateTime.now();
        if(cnt == 1) this.defaultHub = true;
    }

    public void deleteMember() {
        this.member = null;
        this.nickname = null;
        this.joinDate = null;
        this.defaultHub = false;
        cleanModuleInfo();
        cleanModuleSettings();
    }

    private void cleanModuleSettings() {
        this.tempMax = 0.0d;
        this.tempMin = 0.0d;
        this.humidMax = 0.0d;
        this.humidMin = 0.0d;
        this.co2Max = 0.0d;
        this.co2Min = 0.0d;
        this.lightTurnOffTime = LocalDateTime.of(2000, 1, 1, 0, 0, 0);
        this.lightTurnOnTime = LocalDateTime.of(2000, 1, 1, 0, 0, 0);
    }

    private void cleanModuleInfo() {
        this.isTemp = false;
        this.isHumid = false;
        this.isCo2 = false;
        this.isFan = false;
        this.isLight = false;
    }

    public void change2DefaultHub() {
        this.defaultHub = true;
    }

    @Builder
    public Hub(String serial){
        this.serial = serial;
    }

    public void useTempModule() {
        this.isTemp = true;
    }

    public void useHumidModule() {
        this.isHumid = true;
    }

    public void useCo2Module() {
        this.isCo2 = true;
    }

    public void useFanModule() {
        this.isFan = true;
    }

    public void useLightModule() {
        this.isLight = true;
    }
}
