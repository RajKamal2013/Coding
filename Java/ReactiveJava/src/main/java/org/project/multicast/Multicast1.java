package org.project.multicast;

import io.reactivex.rxjava3.core.Observable;
import io.reactivex.rxjava3.observables.ConnectableObservable;

public class Multicast1 {

    public void withoutMulticast() {
        // Creating Observable
        Observable<Integer> ints = Observable.range(1, 5);

        // First Observer
        ints.subscribe(i->{
            System.out.println("Observer One: "+ i);
        });

        // Second Observer
        ints.subscribe(i -> {
            System.out.println("Observer Two " + i);
        });
    }

    public void withMulticast() {
        // Creating Observable
        Observable<Integer> ints = Observable.range(1, 5);

        // Create ConnectableObserver
        ConnectableObservable<Integer> connectableObservable = ints.publish();

        // First Observer
        connectableObservable.subscribe(i->{
            System.out.println("Observer One: "+ i);
        });

        // Second Observer
        connectableObservable.subscribe(i -> {
            System.out.println("Observer Two " + i);
        });

        // Connect the Observable to initiate data flow
        connectableObservable.connect();

    }

    public static void main(String[] args) {
        Multicast1 multicast = new Multicast1();
        System.out.println("Code without Multicasting");
        System.out.println("-----------------------------------------------------------");
        multicast.withoutMulticast();
        System.out.println("-----------------------------------------------------------");
        System.out.println("Code with Multicasting");
        System.out.println("-----------------------------------------------------------");
        multicast.withMulticast();
        System.out.println("-----------------------------------------------------------");
    }
}
