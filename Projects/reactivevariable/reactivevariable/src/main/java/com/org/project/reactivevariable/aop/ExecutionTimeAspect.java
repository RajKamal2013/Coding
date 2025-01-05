package com.org.project.reactivevariable.aop;

import lombok.extern.slf4j.Slf4j;
import org.aspectj.lang.ProceedingJoinPoint;
import org.aspectj.lang.annotation.Around;
import org.aspectj.lang.annotation.Aspect;
import org.springframework.context.annotation.Configuration;

//@Aspect
@Configuration
@Slf4j
public class ExecutionTimeAspect {
    //@Around("execution(* com.org.project.reactivevariable.*.*(..))")
    @Around("com.org.project.reactivevariable.aop.JoinPointConfig.allLayerPointcutPointcut()")
    //@Around("JoinPointConfig.measureTimePointcut()")
    public Object calculateExecutionTime(ProceedingJoinPoint joinPoint) throws Throwable {
        //note start time
        long startTime = System.currentTimeMillis();
        //allow method call to execute
        Object returnValue = joinPoint.proceed();
        //time taken = end time - start time
        long timeTaken = System.currentTimeMillis() - startTime;

        log.info("--------AOP Advice--------: Time taken by {} to complete execution is: {}", joinPoint, timeTaken);
        return returnValue;
    }
}
