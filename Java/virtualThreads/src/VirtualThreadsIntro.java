import java.util.ArrayList;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class VirtualThreadsIntro {
    //private static final int NUM_THREADS = 10000;
    private static final int NUM_THREADS = 10000000;

    public static  void handleUserRequest() {
        System.out.println("Starting Thread " + Thread.currentThread());
        try {
            Thread.sleep(10000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("Ending Thread " + Thread.currentThread());

    }

    /*
     * Platform thread will give exception with number of threads: 10000
     */
    public static void platformThreads() {
        System.out.println("Platform thread: ");
        for (int i=0; i < NUM_THREADS; i++) {
            new Thread(()-> handleUserRequest()).start();
        }
    }

    public static void virtualThreads() throws InterruptedException {
        System.out.println("Virtual Threads: ");
        var threads = new ArrayList<Thread>();
        for(int i=0; i< NUM_THREADS; i++) {
            threads.add(Thread.startVirtualThread(()-> handleUserRequest()));
        }
        for (Thread t: threads) {
            t.join();
        }
    }
    public static void main(String[] args) throws InterruptedException {
        System.out.println(" Starting main thread " + Thread.currentThread());
        virtualThreads();
        System.out.println(" Ending main thread " + Thread.currentThread());
    }
}
