package coding.io;

import java.io.PrintWriter;

public class PrintWriterDemo {
    public static void main(String[] args){
        String data = "This is a text inside the file.";

        try {
            PrintWriter output = new PrintWriter("output.txt");

            output.print(data);
            output.close();
        }
        catch(Exception e) {
            e.getStackTrace();
        }
    }
}
