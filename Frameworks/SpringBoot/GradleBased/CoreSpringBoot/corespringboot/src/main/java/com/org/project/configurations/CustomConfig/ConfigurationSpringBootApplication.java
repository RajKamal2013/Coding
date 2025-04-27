package com.org.project.configurations.CustomConfig;

import com.org.project.corespringboot.CorespringbootApplication;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.CommandLineRunner;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

@SpringBootApplication
@Slf4j
public class ConfigurationSpringBootApplication implements CommandLineRunner {
    @Autowired
    PrintConfigurations printConfigurations;

    public static void main(String[] args) {
        SpringApplication.run(CorespringbootApplication.class, args);

    }

    @Override
    public void run(String... args) throws Exception {
        log.info("Running Spring Boot Application for reading configurations");
        printConfigurations.printConfigurations();
    }

}
