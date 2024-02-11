package coding.io;

import java.io.FileReader;
import java.io.Reader;

public class InputReaderDemo {
    public static void main(String[] args) {

        // Creates an array of character
        char[] array = new char[100];

        try {
            // Creates a reader using the FileReader
            Reader input = new FileReader("input.txt");

            // Checks if reader is ready
            System.out.println("Is there data in the stream?  " + input.ready());

            // Reads characters
            input.read(array);
            System.out.println("Data in the stream:");
            System.out.println(array);

            // Closes the reader
            input.close();
        }

        catch(Exception e) {
            e.getStackTrace();
        }
    }
}
