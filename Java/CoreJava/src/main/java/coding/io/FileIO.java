package coding.io;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.OutputStream;

public class FileIO {

  public static void main(String args[]) {

    byte[] array = new byte[100];

    try {
      System.out.println("Opening File");
      InputStream input = new FileInputStream("input.txt");

      System.out.println("Available bytes in the file: " + input.available());

      // Read byte from the input stream
      input.read(array);
      System.out.println("Data read from the file: ");

      // Convert byte array into string
      String data = new String(array);
      System.out.println(data);

      // Close the input stream
      input.close();
    } catch (Exception e) {
      System.out.println("Caught Exception");
      e.getStackTrace();
    }

    String data = "This is a line of text inside the file.";

    try {
      OutputStream out = new FileOutputStream("output.txt");

      // Converts the string into bytes
      byte[] dataBytes = data.getBytes();

      // Writes data to the output stream
      out.write(dataBytes);
      System.out.println("Data is written to the file.");

      // Closes the output stream
      out.close();
    } catch (Exception e) {
      e.getStackTrace();
    }
  }
}
