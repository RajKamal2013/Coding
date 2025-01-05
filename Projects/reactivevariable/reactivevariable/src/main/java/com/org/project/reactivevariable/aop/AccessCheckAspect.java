package com.org.project.reactivevariable.aop;

import lombok.extern.slf4j.Slf4j;
import org.aspectj.lang.JoinPoint;
import org.aspectj.lang.annotation.Aspect;
import org.aspectj.lang.annotation.Before;
import org.springframework.context.annotation.Configuration;

//@Aspect
@Configuration
@Slf4j
public class AccessCheckAspect {

    //@Before("execution(* com.org.project.reactivevariable.service.*.*Filtering(..)) || execution(String com.org.project.reactivevariable.service..*.*(..))")
    //@Before("execution(String com.org.project.reactivevariable.service..*.*(String))")
    //@Before("execution(* com.org.project.reactivevariable.service..*.*Filtering(..))")
    //@Before("execution(String com.org.project.reactivevariable.service..*.*(..))")
    //@Before("execution(* com.org.project.reactivevariable.service.*.*(..))")
    @Before("JoinPointConfig.movieRepositoryBeanPointcut()")
    public void checkAccess(JoinPoint joinPoint) {
        log.info("--------AOP Advice--------: Access check started before execution of: {}", joinPoint);
    }
}
