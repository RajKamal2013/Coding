package DS.Sorting;

import DS.util.IntegerFileGenerator;

import java.util.Arrays;
import java.util.Vector;

public class SortingTest {

    public static void PrintArrayWithBanner(Vector<Integer> arr, String str) {
        String banner = "---------------";
        System.out.println(banner + str + banner);
        for (int i = 0; i < arr.size(); i++) {
            System.out.print(arr.get(i) + " ");
        }
        System.out.print(banner + banner);
        System.out.println();
    }

    public static void PrintArrayWithBanner(Integer[] arr, String str) {
        String banner = "---------------";
        System.out.println(banner + str + banner);
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.print(banner + banner);
        System.out.println();
    }

    public static void main(String[] args) {
        long start, end, duration;
        int range = 100;
        int size = 100;


        System.out.println("******************QSort Testing **********");
        size = 1000;
        range = 1000;
        IntegerFileGenerator Qgen = new IntegerFileGenerator(size, range , "QsortInput.txt", "QsortOutput.txt");
        Qgen.generate();
        Vector<Integer> Qarr = Qgen.read();
        PrintArrayWithBanner(Qarr, "Input Data");

        start = System.nanoTime();
        Qsort.Sort(Qarr);
        end = System.nanoTime();

        duration = end - start;
        System.out.println("Time taken to sort in ns:"+  duration);
        PrintArrayWithBanner(Qarr, "Output Data");


        System.out.println("*******************Msort Testing ******************");
        size = 1000;
        range = 1000;
        IntegerFileGenerator  Mgen = new IntegerFileGenerator(size, range, "MSortInput.txt", "MsortOutput.txt");
        Mgen.generate();
        Vector<Integer> Marr = Mgen.read();
        PrintArrayWithBanner(Marr, "Input Data");

        start = System.nanoTime();
        MSort.Sort(Marr);
        end = System.nanoTime();

        duration = end - start;
        System.out.println("Time taken to sort in ns:"+  duration);
        PrintArrayWithBanner(Marr, "Output Data");

        System.out.println("*******************Hsort Testing ******************");
        size = 1000;
        range = 1000;
        IntegerFileGenerator Hgen = new IntegerFileGenerator(size, range, "HSortInput.txt", "HsortOutput.txt");
        Hgen.generate();
        Vector<Integer> Harr = Hgen.read();
        PrintArrayWithBanner(Harr, "Input Data");

        start = System.nanoTime();
        HSort.Sort(Harr);
        end = System.nanoTime();
        duration = end - start;
        System.out.println("Time Taken to Sort in ns:" + duration);
        PrintArrayWithBanner(Harr, "Output Data");

        System.out.println("*******************Csort Testing ******************");
        range = 10000;
        size = 700;
        IntegerFileGenerator Cgen = new IntegerFileGenerator(size, range, "CSortInput.txt", "CsortOutput.txt");
        Cgen.generate();
        Vector<Integer> Cvec = Cgen.read();
        Object[] Oarr = Cvec.toArray();
        Integer[] Carr = Arrays.copyOf(Oarr, Oarr.length, Integer[].class);

        if (Carr != null) {
            PrintArrayWithBanner((Integer[]) Carr, "Input Data");

            start = System.nanoTime();
            CSort.Sort((Integer[]) Carr, range);
            end = System.nanoTime();
            duration = end - start;
            System.out.println("Time Taken to Sort in ns:" + duration);
            PrintArrayWithBanner((Integer[]) Carr, "Output Data");
        }

        /*
        try {
            FileWriter sortedFile = new FileWriter(new File("Sorted.txt"));
            sortedFile.append(arr.size() + "\n");
            for (int i = 0; i < arr.size(); i++) {
                sortedFile.append(arr.get(i) + "\n");
            }
            sortedFile.flush();
            sortedFile.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
        */
    }
}
