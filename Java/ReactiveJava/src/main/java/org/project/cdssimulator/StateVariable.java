package org.project.cdssimulator;

public class StateVariable<T> {
    private T state;
    public StateVariable(T data) {
        state = data;
    }

    public void setState(T data) {
        state = data;
    }

    public T getState() {
        return state;
    }

}
