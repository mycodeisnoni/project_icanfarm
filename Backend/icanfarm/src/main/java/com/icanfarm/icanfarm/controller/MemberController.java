package com.icanfarm.icanfarm.controller;

import com.icanfarm.icanfarm.dto.MemberJoinDTO;
import com.icanfarm.icanfarm.service.MemberService;
import lombok.RequiredArgsConstructor;
import org.springframework.http.ResponseEntity;
import org.springframework.security.crypto.bcrypt.BCryptPasswordEncoder;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequiredArgsConstructor
@RequestMapping("/api")
public class MemberController {

    private final MemberService memberService;
    private final BCryptPasswordEncoder encoder;

    @PostMapping("/login")
    public ResponseEntity login(@RequestBody MemberJoinDTO memberJoinDTO){
        Long memberId = memberService.login(memberJoinDTO);

        return ResponseEntity.ok().body(memberId);
    }


}