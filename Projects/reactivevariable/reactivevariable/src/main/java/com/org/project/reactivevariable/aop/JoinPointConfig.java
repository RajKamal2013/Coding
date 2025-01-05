package com.org.project.reactivevariable.aop;

import org.aspectj.lang.annotation.Pointcut;

public class JoinPointConfig {
    @Pointcut("execution(* com.org.project.reactivevariable.model.*.*(..))")
    public void dataLayerPointcut() {}

    @Pointcut("execution(* com.org.project.reactivevariable.service.*.*(..))")
    public void serviceLayerPointcut() {}

    @Pointcut("com.org.project.reactivevariable.aop.JoinPointConfig.dataLayerPointcut() || "
            + "com.org.project.reactivevariable.aop.JoinPointConfig.serviceLayerPointcut()")
    public void allLayerPointcutPointcut() {}

    @Pointcut("bean(movie*)")
    public void movieRepositoryBeanPointcut() {}

    @Pointcut("@annotation(com.org.project.reactivevariable.aop.MeasureTime)")
    public void measureTimePointcut() {}

    //@Pointcut("@annotation(com.org.project.reactivevariable.aop.PublishNotification) && args(arg1, arg2)")
    public void publishNotificationPointcut() {}
}
