package org.project.flowable;

import static java.lang.Thread.sleep;

public class BackpressureWithFlowable {
    public static void main(String[] args) throws InterruptedException {
        io.reactivex.rxjava3.core.Flowable.range(1, 10000)
                .map(MyItem::new)
                .subscribe(myItem -> {
                    sleep(50);
                    System.out.println("Recieved MyItem: " + myItem.id);
                });
        sleep(Long.MAX_VALUE);
    }
}
