package DS.util;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Random;
import java.util.Scanner;
import java.util.Vector;

public class IntegerFileGenerator {
    int size;
    int range;
    String InputFileName;
    String OutputFileName;

    public IntegerFileGenerator(int size, int range) {
        this.size = size;
        this.range = range;
        InputFileName =  "Input.txt";
        OutputFileName = "Output.txt";
    }

    public IntegerFileGenerator(int size, int range, String InputFileName, String OutputFileName) {
        this.size = size;
        this.range = range;
        this.InputFileName =  InputFileName;
        this.OutputFileName = OutputFileName;
    }

    public IntegerFileGenerator(int size, int range, String OutputFileName) {
        this.size = size;
        this.range = range;
        this.InputFileName =  "Input.txt";
        this.OutputFileName = OutputFileName;
    }

    public IntegerFileGenerator(String InputFileName, String OutputFileName) {
        this.size = 0;
        this.InputFileName = InputFileName;
        this.OutputFileName = OutputFileName;
    }


    public IntegerFileGenerator() {
        size = 20;
        range = 100;
        InputFileName =  "Input.txt";
        OutputFileName = "Output.txt";
    }

    public void generate() {
        int data;
        Random rand = new Random();
        try {
            FileWriter output = new FileWriter(new File(InputFileName));
            output.write(size + "\n");
            for (int i = 0;  i < this.size; i++) {
                data = rand.nextInt(range);
                output.append(data + "\n");
            }
            output.flush();
            output.close();
        } catch (IOException ioException) {
            ioException.printStackTrace();
        }
    }

    public void write(Vector<Integer> vec)
    {
        try {
            FileWriter output = new FileWriter(new File(OutputFileName));
            output.write(vec.size() + "\n");
            for(int p : vec) {
                output.append(p + "\n");
            }
            output.flush();
            output.close();
        } catch (IOException e) {
            e.printStackTrace();
        }

    }

    public Vector<Integer> read() {
        Vector<Integer> arr = new Vector<>();
        int rsize;
        int i = 0;
        try {
            Scanner sc = new Scanner(new File(InputFileName));
            rsize = sc.nextInt();
            assert(rsize == this.size);
            while(sc.hasNextInt()) {
                arr.add(i, sc.nextInt());
                i= i+ 1;
            }
        }catch (IOException e) {
            e.printStackTrace();
        }
        return arr;
    }
}


