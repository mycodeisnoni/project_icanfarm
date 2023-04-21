package com.icanfarm.icanfarm.entity;

import lombok.Builder;
import lombok.Getter;
import org.hibernate.annotations.ColumnDefault;
import org.hibernate.annotations.DynamicInsert;

import javax.persistence.*;
import java.util.ArrayList;
import java.util.List;

@DynamicInsert
@Entity
@Getter
@Builder
public class Member {

    @Id
    @GeneratedValue
    private Long id;

    @Column(nullable = false)
    private String name;

    @Column(nullable = false)
    private String email;

    @ColumnDefault("'ROLE_USER'")
    @Enumerated(EnumType.STRING)
    private MemberRole role = MemberRole.ROLE_USER;

    @ColumnDefault("'000000'")
    @Column(name = "rpi_pw")
    private String rpiPasswd;

    @OneToMany(mappedBy = "member")
    private List<Hub> hubs = new ArrayList<>();
}
