package HttpPlayer;

import java.util.Arrays;
import java.util.concurrent.*;
import java.util.stream.Collectors;

public class UserRequestHandler implements Callable<String> {

    @Override
    public String call() throws Exception {
        //return sequentialCall();
        //return concurrentCallWithFutures();
        return concurrentCallFunctional();
    }

    private String concurrentCallWithCompletableFuture() {
        long start = System.currentTimeMillis();
        try(ExecutorService srv = Executors.newVirtualThreadPerTaskExecutor() ) {
            String output = CompletableFuture.supplyAsync(this::dbCall, srv)
                    .thenCombine(
                            CompletableFuture.supplyAsync(this::restCall, srv)
                            , (result1, result2) -> {
                                return "[" + result1 + ", " + result2 +"]";
                            })
                    .thenApply(result -> {
                        String r = externalCall();
                        return "[" + result + ", " + r + "]";
                    })
                    .join();
            long end = System.currentTimeMillis();
            System.out.println("Time =" + (end-start));
            System.out.println("Concurrent call with completable future :" + output);
            return output;
        }
    }

    private String concurrentCallFunctional() throws Exception {
        long start = System.currentTimeMillis();
        try(ExecutorService srv = Executors.newVirtualThreadPerTaskExecutor()) {
            String result = srv.invokeAll(Arrays.asList(this::dbCall, this::restCall)).stream()
                    .map(
                            f -> {
                                try {
                                    return (String)f.get();
                                } catch (Exception e) {
                                    return null;
                                }
                            }
                    )
                    .collect(Collectors.joining(","));
            result =   "[" + result + "]";

            long end = System.currentTimeMillis();
            System.out.println("Time =" + (end-start));
            System.out.println("Concurrent Call Functional Result: " + result);
            return  result;
        }
    }

    private String concurrentCallWithFutures() throws Exception {
        try (ExecutorService srv = Executors.newVirtualThreadPerTaskExecutor()) {
            long start = System.currentTimeMillis();
            Future<String> dbFuture = srv.submit(this::dbCall);
            Future<String> restFuture = srv.submit(this::restCall);

            String result = String.format("[%s, %s]", dbFuture.get(), restFuture.get());
            long end = System.currentTimeMillis();
            System.out.println("Time =" + (end-start));
            System.out.println("Concurrent Call with Future Result: " + result);
            return result;
        }
    }

    private String sequentialCall() throws  Exception {
       long start = System.currentTimeMillis();
       String result1 = dbCall();
       String result2 = restCall();

       String result = String.format("[%s, %s]", result1, result2);
       long end = System.currentTimeMillis();
       System.out.println("Time =" + (end-start));
       System.out.println("Sequential Call Result: " + result);
       return result;
    }

    private String dbCall() {
        try {
            NetworkCall caller = new NetworkCall("DB ");
            return caller.makeCall(2);
        } catch(Exception e) {
            e.printStackTrace();
            return null;
        }
    }

    private String restCall() {
        try {
            NetworkCall caller = new NetworkCall("REST ");
            return caller.makeCall(5);
        } catch(Exception e) {
            e.printStackTrace();
            return null;
        }
    }

    private String externalCall() {
        try {
            NetworkCall caller = new NetworkCall("External ");
            return caller.makeCall(4);
        } catch(Exception e) {
            e.printStackTrace();
            return null;
        }
    }
}
