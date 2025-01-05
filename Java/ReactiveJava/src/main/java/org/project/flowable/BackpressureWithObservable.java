package org.project.flowable;

import io.reactivex.rxjava3.core.Observable;
import io.reactivex.rxjava3.schedulers.Schedulers;

import static java.lang.Thread.sleep;

public class BackpressureWithObservable {
    public static void main(String[] args) {
        Observable.range(1, 10000)
                .map(MyItem::new)
                .observeOn(Schedulers.io())
                .subscribe(
                        myItem -> {
                            sleep(50);
                            System.out.println("Recieved MyItem: " + myItem.id);
                        }
                );
    }
}
