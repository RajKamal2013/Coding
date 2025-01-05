package com.org.project.reactivevariable.aop;

import com.org.project.reactivevariable.construct.ReactiveVariable;
import lombok.extern.slf4j.Slf4j;
import org.aspectj.lang.JoinPoint;
import org.aspectj.lang.annotation.After;
import org.aspectj.lang.annotation.Aspect;
import org.springframework.context.annotation.Configuration;

@Aspect
@Configuration
@Slf4j
public class PublishNotificationAspect {
    //@Before("execution(* com.org.project.reactivevariable.service.*.*(..))")
    //@Before("execution(* com.org.project.reactivevariable.service.*.*(..))")
    //@Before("execution(* com.org.project.reactivevariable.construct.*.*(..))")
   // @After("JoinPointConfig.publishNotificationPointcut()")
    @After("@annotation(com.org.project.reactivevariable.aop.PublishNotification) &&" +
            "args(arg1, arg2)")
    public void PublishNotification(JoinPoint joinPoint, ReactiveVariable arg1, Object arg2) {
        System.out.println("--------AOP Advice--------: Publish notification executed");
        arg1.publish();
        //ReactiveVariable<?> reactiveVariable = (ReactiveVariable) joinPoint.getTarget();
        //reactiveVariable.publish();
    }


   // @After("JoinPointConfig.pushNotificationPointcut()")
    public void PushNotification(JoinPoint joinPoint) {
        log.info("----------------Push notification executed-----------------");

    }
}
