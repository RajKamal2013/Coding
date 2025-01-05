package org.project.subject;

import io.reactivex.rxjava3.annotations.NonNull;
import io.reactivex.rxjava3.core.Observable;
import io.reactivex.rxjava3.core.Observer;
import io.reactivex.rxjava3.disposables.Disposable;
import io.reactivex.rxjava3.subjects.PublishSubject;
import io.reactivex.rxjava3.subjects.Subject;
import lombok.AllArgsConstructor;
import lombok.Getter;


@Getter
public class DataEmittorImpl<T> implements DataEmitter<T> {
    Subject<String> subject = PublishSubject.create();

    @Override
    public void emit(Object item) {
        subject.onNext("Hi");
        subject.onNext("Hello");
        subject.onNext(item.toString());
    }

    public Observable<T> getObservable() {
        return (Observable<T>) subject;
    }


    public static void main(String[] args) {
        Observer<String> observer = new Observer<String>() {
            @Override
            public void onSubscribe(@NonNull Disposable d) {

            }

            @Override
            public void onNext(@NonNull String s) {
                System.out.println("Data Recieved: " + s);
            }

            @Override
            public void onError(@NonNull Throwable e) {

            }

            @Override
            public void onComplete() {

            }
        };
        DataEmitter emitter = new DataEmittorImpl();

        Observable<String> publisher = ((DataEmittorImpl<String>) emitter).getObservable();
        publisher.subscribe(observer);
        ((DataEmittorImpl<?>) emitter).getObservable().subscribe(System.out::println);

        emitter.emit("Raj");
        emitter.emit("Tarun");
        System.out.println("emitter emission done");

    }
}
