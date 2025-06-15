package DS.List;

import java.io.*;

public class ListTest {
    private List<Integer> L1;
    private List<Integer> L2;

    public static boolean find(List<Integer> L, int k ) {
        for (L.moveToStart(); L.currPos() < L.length(); L.next()) {
            if (k == L.getValue()) {
                return true;
            }
        }
        return false;
    }

    public void setup() {
        L1 = new LList<Integer>();
        L2 = new LList<Integer>();
    }

    public void testRemove() {
        L2.append(1);
        assert("<  1>" ==  L2.toString());
    }

    public void testAppend(){
        L2.append(10);
        System.out.println(L2.toString());
    }

    public void testFind(){
        L1.moveToStart();
        L1.insert(39);
        L1.next();
        L1.insert(9);
        L1.next();
        L1.insert(5);
        L1.next();
        L1.insert(1);
        L1.next();
        L1.insert(2);
        L1.append(3);
        L1.append(4);
        L1.moveToStart();
        L1.insert(0);
        System.out.println(L1.toString());
        System.out.println("2 is present:" + find(L1,2));
        System.out.println("10 is present:" + find(L1,10));
    }

    public static void main(String[] args) {
        ListTest test  = new ListTest();
        test.setup();
        test.testRemove();
        test.testAppend();
        test.testFind();
    }

}
