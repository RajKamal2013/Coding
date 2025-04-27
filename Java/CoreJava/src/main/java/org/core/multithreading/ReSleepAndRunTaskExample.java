package org.core.multithreading;


import java.util.concurrent.*;

    public class ReSleepAndRunTaskExample {
        public static void main(String[] args) throws InterruptedException {
            ExecutorService executor = Executors.newSingleThreadExecutor();

            // Submit the task to the executor
            Future<?> future = executor.submit(new ReSleepAndRunTask());

            // Sleep for a short time before interrupting the task
            Thread.sleep(20000);

            // Cancel the task with interruption to wake it up
            boolean canceled = future.cancel(true);
            System.out.println("First cancel call: " + canceled);

            // Sleep for a short time before re-interrupting the task
            //Thread.sleep(3000);

            // Submit the task again if it was canceled and interrupted

            if (canceled) {
                 future = executor.submit(new ReSleepAndRunTask());
                System.out.println("New task submitted");
            }

            // Sleep for a short time before interrupting the new task
            Thread.sleep(20000);
            canceled = future.cancel(true);
            System.out.println("Second cancel call: " + canceled);

            if (canceled) {
                future = executor.submit(new ReSleepAndRunTask());
                System.out.println("New task submitted");
            }

            Thread.sleep(20000);
            canceled = future.cancel(true);
            System.out.println("Third cancel call: " + canceled);

            if (canceled) {
                future = executor.submit(new ReSleepAndRunTask());
                System.out.println("New task submitted");
            }

            Thread.sleep(20000);
            canceled = future.cancel(true);
            System.out.println("Fourth cancel call: " + canceled);

            executor.shutdown();
        }
    }

    class ReSleepAndRunTask implements Runnable {
        @Override
        public void run() {
            while (true) {
                int i = 0;
                try {
                    System.out.println("Task Started and it is going to sleep again...");
                    Thread.sleep(10000); // Simulate a long sleep
                    //System.out.println("Task woke up naturally");
                } catch (InterruptedException e) {
                    i++;
                    System.out.println("Task was interrupted and woke up: "+ i);
                    // Perform any necessary cleanup or reset logic here
                    // Optionally, check for interruption status and break if necessary
                    if (Thread.currentThread().isInterrupted()) {
                        System.out.println("Task is interrupted and will exit or handle interruption");
                        //break; // Exit loop or reset state based on your logic
                    }
                    System.out.println("Task woke up after exception, continues to run...");
                    break;
                }
                // Additional logic after waking up
            }
        }
    }
