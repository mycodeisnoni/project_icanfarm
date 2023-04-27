//package com.icanfarm.icanfarm.service;
//
//import io.jsonwebtoken.Claims;
//import io.jsonwebtoken.ExpiredJwtException;
//import io.jsonwebtoken.Jwts;
//import io.jsonwebtoken.SignatureAlgorithm;
//import lombok.extern.slf4j.Slf4j;
//import org.springframework.stereotype.Component;
//
//import java.io.UnsupportedEncodingException;
//import java.util.Date;
//import java.util.HashMap;
//import java.util.Map;
//
//@Slf4j
//@Component
//public class TokenProvider {
//    private final String key = "jsonwebtoken";
//
//    public String createToken(Long memberId) {
//        Map<String, Object> headers = new HashMap<>();
//        headers.put("typ", "JWT");
//        headers.put("Alg", "HS256");
//
//        Map<String, Object> payloads = new HashMap<>();
//        //payloads.put("data", "JWT Test");
//
//        // 24H
//        Long expiredTime = 1000 * 60L * 60L * 24L;
//
//        Date ext = new Date();
//        ext.setTime(ext.getTime() + expiredTime); // 현재시간 + expiredTime
//
//        String jwt = Jwts.builder()
//                .setHeader(headers)
//                .setClaims(payloads)
//                .setSubject(memberId.toString())
//                .setIssuer("pomyharry")
//                .setIssuedAt(new Date())
//                .setExpiration(ext)
//                .signWith(SignatureAlgorithm.HS512, key.getBytes())
//                .compact();
//
//        return jwt;
//    }
//    // 암호화된 토큰을 다시 코드만 뽑기
//    public String verifyJWT(String token) throws UnsupportedEncodingException {
//        Claims claims = null;
//        try {
//            claims = Jwts.parser()
//                    .setSigningKey(key.getBytes("UTF-8"))
//                    .parseClaimsJws(token)
//                    .getBody();
//
//        } catch (ExpiredJwtException e) {
//            log.error("Token is Expired...");
//
//        } catch (Exception e) {
//            log.error("You got an error : " + e.getMessage());
//        }
//
//        return claims.getSubject();
//    }
//}
