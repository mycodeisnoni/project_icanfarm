package com.icanfarm.icanfarm.service;

import com.icanfarm.icanfarm.dto.MemberJoinDTO;
import com.icanfarm.icanfarm.entity.Member;
import com.icanfarm.icanfarm.exception.PasswdInvalidException;
import com.icanfarm.icanfarm.exception.UserNotExistException;
import com.icanfarm.icanfarm.repository.MemberRepository;
import lombok.RequiredArgsConstructor;
import org.springframework.security.crypto.bcrypt.BCryptPasswordEncoder;
import org.springframework.stereotype.Service;

import java.util.Optional;

@Service
@RequiredArgsConstructor
public class MemberService {

    private final MemberRepository memberRepository;
    private final BCryptPasswordEncoder encoder;

    private final TokenProvider tokenManager;

    public Long login(MemberJoinDTO memberJoinDTO) {

        Optional<Member> findMemberOpt = memberRepository.findByEmail(memberJoinDTO.getEmail());

        if(findMemberOpt.isEmpty())
            throw new UserNotExistException();

        Member findMember = findMemberOpt.get();

        if(!encoder.matches(memberJoinDTO.getPasswd(), findMember.getPasswd()))
            throw new PasswdInvalidException();

        String token = tokenManager.createToken(findMember.getId());

//        UsernamePasswordAuthenticationToken authenticationToken = new UsernamePasswordAuthenticationToken(findMember.getId(), null, AuthorityUtils.NO_AUTHORITIES);
//        Authentication authentication = authenticationManagerBuilder.getObject().authenticate(authenticationToken);
//
//        JwtToken token = jwtProvider.generateToken(authentication);

//        return token;
        return findMember.getId();
    }

    public Member getMember(Long memberId){
        Optional<Member> findMember = memberRepository.findById(memberId);

        if(findMember.isEmpty())
            throw new UserNotExistException();

        return findMember.get();
    }
}
