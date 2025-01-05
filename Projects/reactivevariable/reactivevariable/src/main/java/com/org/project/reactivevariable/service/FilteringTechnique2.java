package com.org.project.reactivevariable.service;

import com.org.project.reactivevariable.aop.MeasureTime;
import com.org.project.reactivevariable.model.UserRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

@Service
public class FilteringTechnique2 {
    @Autowired
    private UserRepository userRepository;

    @MeasureTime
    public String collaborativeFiltering() {
        String userDetails =  userRepository.getUserDetails();
        return userDetails;
    }
}
