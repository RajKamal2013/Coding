package DS.SortedList;

public class SortedTest {
    private SortedList<Integer, Integer> L1;
    private SortedList<String, String> L2;
    private SortedList<String, Payroll> L3;

    public void setup() {
        L1 = new SAList<Integer, Integer>();
        L2 = new SAList<String, String>(15);
        L3 = new SAList<String, Payroll>();
    }

    public static <Key, E> E find (SortedList<Key, E> L, Key k) {
        Key itKey;
        for (L.moveToStart(); L.currPos() < L.length(); L.next()) {
            itKey = L.getKey();
            if (itKey ==  k) {
                return L.getValue();
            }
        }
        return null;
    }

    public void test() {
        L1.clear();
        L2.clear();
        L3.clear();
        L1.insert(30, 30);
        L1.insert(90, 90);
        L1.insert(5, 5);
        L1.moveToStart();
        L1.insert(1, 1);
        int key = 90;
        int val = find(L1, key);
        System.out.println("Key " + key + " - " + val );
        System.out.println(L1.toString());
    }

    public static void main(String [] args) {
        SortedTest test = new SortedTest();
        test.setup();
        test.test();
    }


}
