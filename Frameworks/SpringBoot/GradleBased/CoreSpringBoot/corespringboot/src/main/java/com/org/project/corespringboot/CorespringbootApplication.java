package com.org.project.corespringboot;

import com.org.project.corespringboot.PrintConfigurations;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.CommandLineRunner;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

@SpringBootApplication
@Slf4j
public class CorespringbootApplication implements CommandLineRunner {

    @Autowired
    PrintConfigurations printConfigurations;

    public static void main(String[] args) {
        SpringApplication.run(CorespringbootApplication.class, args);

    }

    @Override
    public void run(String... args) throws Exception {
       log.info("Hello World: Spring Boot Application");
       printConfigurations.printConfigurations();
    }
}
