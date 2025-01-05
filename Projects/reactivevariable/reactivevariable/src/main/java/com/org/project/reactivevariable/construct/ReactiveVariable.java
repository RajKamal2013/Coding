package com.org.project.reactivevariable.construct;

import com.org.project.reactivevariable.aop.MeasureTime;
import com.org.project.reactivevariable.aop.PublishNotification;
import io.reactivex.rxjava3.core.Observable;
import io.reactivex.rxjava3.subjects.PublishSubject;

public class ReactiveVariable<T> {
    private T currentState;
    private final PublishSubject<T> stateSubject;

    public ReactiveVariable(T data) {
        this.currentState = data;
        this.stateSubject = PublishSubject.create();
    }

    //@MeasureTime
    //@PublishNotification
    public void setCurrentState(T currentState) {
        this.currentState = currentState;

    }

    public void set(T currentState) {
        this.currentState = currentState;
        publish();
    }

    public void publish() {
        stateSubject.onNext(this.currentState);
    }

    public Observable<T> getStateObservable() {
        return stateSubject;
    }
}