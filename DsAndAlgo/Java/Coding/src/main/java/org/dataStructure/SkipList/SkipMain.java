package DS.SkipList;

import java.io.IOException;
import java.util.Optional;

public class SkipMain {

    public static void main (String args[]) throws IOException {
        SkipList<Integer, Integer> dum = new SkipList<Integer, Integer>();
        dum.insert(10, 10);
        //dum.print();
        dum.insert(5,5);
        dum.insert(50, 50);
        dum.insert(100, 100);
        dum.insert(120, 120);
        dum.insert(150, 150);
        dum.insert(500, 500);
        dum.printEverything();
        System.out.println();
        System.out.println("Key 10: " + dum.find(10));
        System.out.println("Key 200 " + dum.find(200));
        System.out.println();
        System.out.println();
        int d = dum.remove(100);
        System.out.println();
        dum.printEverything();
    }
}
