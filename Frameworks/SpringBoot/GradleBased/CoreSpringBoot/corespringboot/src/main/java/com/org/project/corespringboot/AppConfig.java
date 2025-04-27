package com.org.project.corespringboot;

import org.springframework.context.annotation.Configuration;
import org.springframework.context.annotation.PropertySource;

@Configuration
@PropertySource("classpath:constants.properties")
public class AppConfig {
}