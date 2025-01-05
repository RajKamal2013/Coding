package org.project.cdssimulator;

public class Driver {
    public static void main(String[] args) {
        StateConstruct<String> var = new StateConstruct<>("Hello");
        var.getStateObservable().subscribe(state -> System.out.println("State Changed to: " + state.getState()));
        var.set("World");
        var.set("Whats next");
        var.set("Next is state changed");
    }
}
