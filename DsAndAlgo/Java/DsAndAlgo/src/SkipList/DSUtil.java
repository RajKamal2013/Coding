package DS.SkipList;

import java.util.Random;

public class DSUtil <E> {
    static private Random value = new Random();

    static int random(int n ) {
        return Math.abs(value.nextInt()) % n;
    }

}
