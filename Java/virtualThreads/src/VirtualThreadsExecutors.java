import com.sun.security.jgss.GSSUtil;

import java.util.ArrayList;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.ThreadFactory;

public class VirtualThreadsExecutors {
    public static  void handleUserRequest() {
        System.out.println("Starting Thread " + Thread.currentThread());
        try {
            Thread.sleep(10000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("Ending Thread " + Thread.currentThread());

    }

    private static void virtualThreadsCreation() throws InterruptedException {
        System.out.println("Virtual Thread creation");
        var threads = new ArrayList<Thread>();
        threads.add(Thread.startVirtualThread(()->handleUserRequest()));
        threads.add(Thread.startVirtualThread(()->handleUserRequest()));

        for(Thread t:threads) {
            t.join();
        }
    }
    private static void virtualThreadsCreationUsingBuilder() throws InterruptedException {
        System.out.println("Virtual Thread creation using Builder");
        Thread.Builder.OfVirtual virtualThreadBuilder = Thread.ofVirtual().name("userThread", 0);
        Thread vThread1 = virtualThreadBuilder.start(()-> handleUserRequest());
        Thread vThread2 = virtualThreadBuilder.start(()-> handleUserRequest());

        vThread1.join();
        vThread2.join();
    }

    private static void virtualThreadsCreationUsingFactory() throws InterruptedException {
        System.out.println("Virtual Thread creation using Factory");
        ThreadFactory virtualThreadFactory = Thread.ofVirtual().name("userthread", 0).factory();

        Thread vThread1 = virtualThreadFactory.newThread(()-> handleUserRequest());
        Thread vThread2 = virtualThreadFactory.newThread(()-> handleUserRequest());

        vThread1.join();
        vThread2.join();
    }

    private static void virtualThreadCreationUsingExecutor() {
        System.out.println("Virtual Thread creation using Executor Service");
        try (ExecutorService srv = Executors.newVirtualThreadPerTaskExecutor()) {
            srv.submit(()-> handleUserRequest());
            srv.submit(()-> handleUserRequest());
        }
    }

    private static void virtualThreadCreationUsingCustomExecutor() {
        System.out.println("Virtual Thread creation using custom Executor Service");
        ThreadFactory virtualThreadFactory = Thread.ofVirtual().name("userthread", 0).factory();
        try (ExecutorService srv = Executors.newThreadPerTaskExecutor(virtualThreadFactory)) {
            srv.submit(()-> handleUserRequest());
            srv.submit(()-> handleUserRequest());
        }
    }

    public static void main(String[] args) throws InterruptedException {
        System.out.println("Main Thread :" + Thread.currentThread().threadId());
        virtualThreadsCreation();
        virtualThreadsCreationUsingBuilder();
        virtualThreadsCreationUsingFactory();
        virtualThreadCreationUsingExecutor();
        virtualThreadCreationUsingCustomExecutor();
        System.out.println("Main Thread :" + Thread.currentThread().threadId());

    }
}
