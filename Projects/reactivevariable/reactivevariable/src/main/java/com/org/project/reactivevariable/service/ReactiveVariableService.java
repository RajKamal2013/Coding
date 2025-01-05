package com.org.project.reactivevariable.service;

import com.org.project.reactivevariable.aop.PublishNotification;
import com.org.project.reactivevariable.construct.ReactiveVariable;
import org.springframework.stereotype.Service;

@Service
public class ReactiveVariableService {
    public <T> void executeChanges(ReactiveVariable reactiveVariable, T value) {
        reactiveVariable.setCurrentState(value);
        reactiveVariable.publish();
    }

    @PublishNotification
    public <T> void executeChanges2(ReactiveVariable reactiveVariable, T value) {
        reactiveVariable.setCurrentState(value);
    }
}
