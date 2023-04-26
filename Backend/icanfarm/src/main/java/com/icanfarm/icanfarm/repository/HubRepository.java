package com.icanfarm.icanfarm.repository;

import com.icanfarm.icanfarm.entity.Hub;
import org.springframework.data.domain.PageRequest;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.Query;
import org.springframework.stereotype.Repository;

import java.awt.print.Pageable;
import java.util.Optional;

@Repository
public interface HubRepository extends JpaRepository<Hub, Long> {
    Optional<Hub> findBySerial(String serial);

    @Query("select hub from Hub hub where hub.member is NULL")
    Optional<Hub> findUnusedOne();
}
