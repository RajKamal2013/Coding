package com.org.project.configurations.CustomConfig;

import org.springframework.context.annotation.Configuration;
import org.springframework.context.annotation.PropertySource;

@Configuration
@PropertySource("classpath:com.org.project.configurations/custom-config.properties")
public class properties {
}