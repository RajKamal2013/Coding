package HttpPlayer;

import lombok.AllArgsConstructor;

import java.io.InputStream;
import java.net.URI;

public class NetworkCall {
    private String callName;


    public NetworkCall(String callName) {
        this.callName = callName;
    }

    public String makeCall(int secs) throws Exception {
        System.out.println("Calling " + callName + " on " + Thread.currentThread().getName());
        try {
            URI uri = new URI("http://httpbin.org/delay/" + secs);
            try (InputStream stream = uri.toURL().openStream()) {
                return new String(stream.readAllBytes());
            }
        } finally {
            System.out.println(" Completed calling " + callName + " on " + Thread.currentThread().getName());
        }
    }
}
