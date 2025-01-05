package org.project.cdssimulator;

import io.reactivex.rxjava3.core.Observable;
import io.reactivex.rxjava3.subjects.PublishSubject;

public class StateConstruct<T> {
    private final StateVariable<T> currentState;
    private final PublishSubject<StateVariable<T>> stateSubject;

    public StateConstruct(T data) {
        this.currentState = new StateVariable<T>(data);
        this.stateSubject = PublishSubject.create();
    }

    public void set(T newState) {
        this.currentState.setState(newState);
        stateSubject.onNext(this.currentState);
    }

    public Observable<StateVariable<T>> getStateObservable() {
        return stateSubject;
    }
}
