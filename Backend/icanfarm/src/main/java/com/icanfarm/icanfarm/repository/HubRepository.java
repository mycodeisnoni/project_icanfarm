package com.icanfarm.icanfarm.repository;

import com.icanfarm.icanfarm.entity.Hub;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

@Repository
public interface HubRepository extends JpaRepository<Hub, Long> {
}
