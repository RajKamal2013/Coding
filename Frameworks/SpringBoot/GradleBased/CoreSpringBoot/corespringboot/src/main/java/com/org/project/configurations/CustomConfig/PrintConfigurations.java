package com.org.project.configurations.CustomConfig;

import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Component;

@Component
@Slf4j
public class PrintConfigurations {
    @Value("${constants.timeoutInSeconds}")
    private int timeoutInSeconds;

    public void printConfigurations() {
        System.out.println("Timeout in seconds: " + timeoutInSeconds);
        log.info("Timeout in seconds: " + timeoutInSeconds);
    }
}
