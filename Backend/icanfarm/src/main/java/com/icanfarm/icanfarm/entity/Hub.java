package com.icanfarm.icanfarm.entity;

import lombok.Builder;
import lombok.Getter;
import lombok.Setter;
import org.hibernate.annotations.ColumnDefault;
import org.hibernate.annotations.DynamicInsert;

import javax.persistence.*;

@DynamicInsert
@Entity
@Getter
@Setter
@Builder
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
    private Double tempMax;

    @Column(name = "temp_min")
    private Double tempMin;

    @Column(name = "humid_max")
    private Double humidMax;

    @Column(name = "humid_min")
    private Double humidMin;

    @Column(name = "co2_max")
    private Double co2Max;

    @Column(name = "co2_min")
    private Double co2Min;
}
