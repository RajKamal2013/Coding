package DS.SortedArrayList;

public class ListTest {
    private SAList<Integer, Integer> L1;

    public void setup() {
        L1 = new SortedAList<Integer, Integer>(30);
    }

    public void testInsert() {
        L1.clear();
        L1.insert(10, 10);
        L1.insert(5, 5);
        L1.insert(100, 100);
        L1.insert(-1, -1);
        System.out.println(L1);

        /* Search test */
        int key = 10;
        int val;
        Object data = L1.find(key);
        if (data != null) {
            val  = (int)data;
            System.out.println("Value for Key:" + key + ": " + val);
        } else {
            System.out.println("Key does not exist:" + key);
        }

        key = 2;
        data = L1.find(key);
        if (data != null) {
            val  = (int)data;
            System.out.println("Value for Key:" + key + ": " + val);
        } else {
            System.out.println("Key:" + key + " does not exist.");
        }

        /* Remove Test */
        data = L1.remove();
        System.out.println(L1);
        L1.insert(50, 50);
        System.out.println(L1);
        L1.delete(50);
        System.out.println(L1);
    }





    public static void main(String[] args) {
        ListTest test = new ListTest();
        test.setup();
        test.testInsert();
        System.out.println("Test Completed!!");

    }
}
