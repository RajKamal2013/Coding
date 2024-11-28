package org.project;

import io.reactivex.rxjava3.core.Observable;
import io.reactivex.rxjava3.core.Scheduler;
import io.reactivex.rxjava3.schedulers.Schedulers;

import java.util.ArrayList;
import java.util.List;

public class App {

    public static Observable<User> getUsersWithBlog(List<User> users) {
        Observable<User> usersWithBlog = Observable.fromIterable(users)
                .filter(user->user.hasBlog())
                .subscribeOn(Schedulers.io());
        return usersWithBlog;
    }

    public static void main(String[] args) {
        User user1, user2, user3;
        user1 = new User("Jack", true, 121);
        user2 = new User("Chris", true, 122);
        user3 = new User("Max", false, 123);
        List<User> users = new ArrayList<>();
        users.add(user1);
        users.add(user2);
        users.add(user3);

        Observable<User> usersWithBlog = getUsersWithBlog(users);
        usersWithBlog.subscribe(
                user-> System.out.println("Username: " + user.username + " " + "\n" + "User ID: " + user.id + "\n"));
        try {
            Thread.sleep(10);
        } catch (InterruptedException ex) {
            System.out.println(ex.getMessage());
            ex.printStackTrace();
        }
    }
}
