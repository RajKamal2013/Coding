package DS.SortedArrayList;

public class DicTest {
    SortedDictionary<Integer, Integer> dic;


    public void setup() {
        dic = new SortedDictionary(20);
    }

    public void testInsert() {
        dic.insert(10, 10);
        dic.insert(1, 1);
        dic.insert(200, 200);
        System.out.println(dic);
        Object val;
        int data;
        int key;

        key = -10;
        val = dic.find(key);
        if (val != null) {
            System.out.println("Key: " + key + " exist, Value: " + val);
        } else {
            System.out.println("Key:" + key + " does not exist!!");
        }

        key = 1;
        val = dic.find(key);
        if (val != null) {
            System.out.println("Key: " + key + " exist, Value: " + val);
        } else {
            System.out.println("Key:" + key + "does not exist!!");
        }
    }

    public static void main(String[] args) {
        DicTest test = new DicTest();
        test.setup();
        test.testInsert();
    }
}
