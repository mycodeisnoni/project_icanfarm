package com.icanfarm.icanfarm.repository;

import com.icanfarm.icanfarm.entity.FarmSensor;
import org.springframework.data.mongodb.repository.MongoRepository;

public interface FarmSensorRepository extends MongoRepository<FarmSensor, Long> {
}
