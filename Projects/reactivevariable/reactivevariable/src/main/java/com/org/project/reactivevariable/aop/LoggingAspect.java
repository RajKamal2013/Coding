package com.org.project.reactivevariable.aop;

import lombok.extern.slf4j.Slf4j;
import org.aspectj.lang.JoinPoint;
import org.aspectj.lang.annotation.After;
import org.aspectj.lang.annotation.AfterReturning;
import org.aspectj.lang.annotation.AfterThrowing;
import org.aspectj.lang.annotation.Aspect;
import org.springframework.context.annotation.Configuration;

//@Aspect
@Configuration
@Slf4j
public class LoggingAspect {

    //@AfterReturning(
    //        value = "execution(* com.org.project.reactivevariable.service.*.*(..))",
    //        returning = "result")
    @AfterReturning(value ="JoinPointConfig.serviceLayerPointcut()", returning = "result")
    public void logAfterReturning(JoinPoint joinPoint, Object result) {
        log.info(joinPoint.getSignature().getDeclaringTypeName() + "." + joinPoint.getSignature().getName());
        log.info("--------AOP Advice--------:  Method {} returned with: {}", joinPoint, result);
    }
    /*
    @AfterThrowing(
            value = "execution(* com.org.project.reactivevariable.service.*.*(..))",
            throwing = "exception")
     */
    @AfterThrowing(value = "JoinPointConfig.serviceLayerPointcut()", throwing = "exception")
    public void LogAfterException(JoinPoint joinPoint, Object exception) {
        log.info("--------AOP Advice--------: Method {} returned with exception: {}", joinPoint, exception);
    }

    /*
    @After(
             value = "execution(* com.org.project.reactivevariable.service.*.*(..))")
     */
    @After(value = "JoinPointConfig.serviceLayerPointcut()")
    public void LogAfterMethod(JoinPoint joinPoint) {
        log.info("--------AOP Advice--------: After method call {}", joinPoint);
    }
}
