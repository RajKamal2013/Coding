package DS.AList;

public class AListTest {

    private List<Integer> L1;
    private List<Integer> L2;
    private List<Object> L3;

    private List<KVPair<Integer, Integer>> L4;
    private List<KVPair<String, Payroll>> L5;

    public static boolean find(List<Integer>L, int K) {
        for (L.moveToStart(); L.currPos() < L.length(); L.next()) {
            if (K == L.getValue()) {
                return true;
            }
        }
        return false;
    }

    public void setUp() {
        L1 = new AList<Integer>();
        L2 = new AList<Integer>(15);
        L3 = new AList<Object>();
        L4 = new AList<KVPair<Integer, Integer>>();
        L5 = new AList<KVPair<String, Payroll>>();
    }


    public void testKVPairInList4(){
        L4.clear();
        KVPair<Integer, Integer> dum = new KVPair<Integer, Integer>(3, 3);
        L4.insert(dum);
        assert (1 == L4.length());
        System.out.print("L4-> ");
        System.out.println(L4);
    }

    public void testKVPairInList5() {
        L5.clear();
        KVPair<String, Payroll> dum2  = new KVPair<String, Payroll>("Hello", new Payroll(5, "Raj", "Bangalore"));
        L5.insert(dum2);
        assert(1 == L5.length());
        System.out.print("L5-> ");
        System.out.println(L5);
    }

    public void testRemove() {
        L2.clear();
        L2.append(1);
        assert("< | 1>" == L2.toString());
        assert(1 == (int)L2.remove());
        assert("< | >" == L2.toString());
        assert(null == L2.remove());
        System.out.print("L2 ->");
        System.out.println(L2);
    }

    public void testAppend() {
        L2.clear();
        L2.append(10);
        assert("< | 10 >" ==  L2.toString());
        L2.append(20);
        L2.append(15);
        assert ("< | 10 20 15 >" == L2.toString());
        System.out.print("L2 ->");
        System.out.println(L2);
    }

    public void testFind() {
        L1.clear();
        L1.moveToStart();
        System.out.print("L1 ->");
        System.out.println(L1);
        L1.insert(10);
        L1.next();
        L1.insert(1);
        L1.insert(2);
        L1.insert(3);
        L1.insert(4);
        L1.insert(5);
        L1.insert(9);
        L1.insert(6);
        System.out.print("L1 ->");
        System.out.println(L1);
        L1.append(11);
        L1.append(7);
        System.out.print("L1 ->");
        System.out.println(L1);
        assert("< 10 | 6 9 5 4 3 2 1 11 7 >" == L1.toString());
        assert(true == find(L1, 1));
        assert(true == find(L1, 7));
        assert(true == find(L1, 11));
        assert(false == find(L1, 20));
    }

    public void testListOfObjects() {
        L3.clear();
        assert ("< | >" == L3.toString());
        L3.insert(3);
        assert ("< | 3 >" == L3.toString());
        L3.insert("Hello");
        assert ("< | Hello 3 >" == L3.toString());
    }

    public void testNext() {
        L2.clear();
        L2.append(10);
        L2.append(20);
        L2.append(15);
        L2.moveToStart();
        L2.next();
        assert (20  == (int)L2.getValue());
    }

    public static void main(String[] args) {
        AListTest test = new AListTest();
        test.setUp();
        test.testFind();
        test.testAppend();
        test.testRemove();
        test.testNext();
        test.testListOfObjects();
        test.testKVPairInList4();
        test.testKVPairInList5();
    }
}
