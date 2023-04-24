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

    private final int FIRST_HUB = 1;

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

    @Column(name = "join_date")
    private LocalDateTime joinDate;

    public void registerMember(Member member, int cnt){
        this.member = member;
        this.nickname = "hub" + cnt;
        this.joinDate = LocalDateTime.now();
        if(cnt == FIRST_HUB) this.defaultHub = true;
    }

    public void deleteMember() {
        this.member = null;
        this.nickname = null;
        this.joinDate = null;
        this.defaultHub = false;
    }

    public void change2DefaultHub() {
        this.defaultHub = true;
    }

    @Builder
    public Hub(String serial){
        this.serial = serial;
    }
}
