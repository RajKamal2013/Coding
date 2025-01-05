package com.org.project.reactivevariable;

import com.org.project.reactivevariable.construct.ReactiveVariable;
import com.org.project.reactivevariable.service.FilteringTechnique1;
import com.org.project.reactivevariable.service.FilteringTechnique2;
import com.org.project.reactivevariable.service.ReactiveVariableService;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.CommandLineRunner;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

@SpringBootApplication
@Slf4j
public class ReactiveVariableApplication implements CommandLineRunner {
    @Autowired
    FilteringTechnique1 filter1;

    @Autowired
    FilteringTechnique2 filter2;

    @Autowired
    ReactiveVariableService reactiveVariableService;

    public static void main(String[] args) {
        SpringApplication.run(ReactiveVariableApplication.class, args);
    }

    @Override
    public void run(String... args) throws Exception {
        log.info("{}",filter1.contentBasedFiltering());
        log.info("{}",filter2.collaborativeFiltering());

        ReactiveVariable<Integer> rvar = new ReactiveVariable<>(1);
        rvar.getStateObservable().subscribe(intVar->
                System.out.println("-------- Reactive Variable is updated------- " +
                        intVar.toString()));
        reactiveVariableService.executeChanges(rvar, 3);
        reactiveVariableService.executeChanges2(rvar, 2);
    }

}
