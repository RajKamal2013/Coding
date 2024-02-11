package coding.io;

import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.FileInputStream;
import java.io.FileOutputStream;

public class BufferedInputStreamDemo {
    public static void main(String[] args) {
        try {
            // Creates a FileInputStream
            FileInputStream file = new FileInputStream("input.txt");

            // Creates a BufferedInputStream
            BufferedInputStream input = new BufferedInputStream(file);

            // Reads first byte from file
            int i = input .read();

            while (i != -1) {
                System.out.print((char) i);

                // Reads next byte from the file
                i = input.read();
            }
            input.close();

            // Suppose, the input.txt file contains the following text
            // This is a line of text inside the file.
            file = new FileInputStream("input.txt");

            // Creates a BufferedInputStream
            BufferedInputStream buffer = new BufferedInputStream(file);

            // Returns the available number of bytes
            System.out.println("Available bytes at the beginning: " + buffer.available());

            // Reads bytes from the file
            buffer.read();
            buffer.read();
            buffer.read();

            // Returns the available number of bytes
            System.out.println("Available bytes at the end: " + buffer.available());

            buffer.close();
        } catch (Exception e) {
            e.getStackTrace();
        }

        try {
            // Suppose, the input.txt file contains the following text
            // This is a line of text inside the file.
            FileInputStream file = new FileInputStream("input.txt");

            // Creates a BufferedInputStream
            BufferedInputStream buffer = new BufferedInputStream(file);

            // Skips the 5 bytes
            buffer.skip(5);
            System.out.println("Input stream after skipping 5 bytes:");

            // Reads the first byte from input stream
            int i = buffer.read();
            while (i != -1) {
                System.out.print((char) i);

                // Reads next byte from the input stream
                i = buffer.read();
            }

            // Closes the input stream
            buffer.close();
        } catch (Exception e) {
            e.getStackTrace();
        }

        String data = "This is a demo of the flush method";

        try {
            // Creates a FileOutputStream
            FileOutputStream file = new FileOutputStream(" flush.txt");

            // Creates a BufferedOutputStream
            BufferedOutputStream buffer = new BufferedOutputStream(file);

            // Writes data to the output stream
            buffer.write(data.getBytes());

            // Flushes data to the destination
            buffer.flush();
            System.out.println("Data is flushed to the file.");
            buffer.close();
        } catch(Exception e) {
            e.getStackTrace();
        }
    }
}
