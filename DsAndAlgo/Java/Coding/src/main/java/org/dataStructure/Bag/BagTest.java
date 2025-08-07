package DS.Bag;

public class BagTest {
    public Bag<String> b;

    BagTest() {
        setup();
    }

    public void setup() {
        b = new Bag<String>();
    }

    public void testAdd() {
        String item = "Hi";
        b.add(item);
        item = "I am Raj Kamal.";
        b.add(item);
        item = "This is new thing for me.";
        b.add(item);
        System.out.println(b);
    }

    public static void main(String[]args) {
        BagTest test = new BagTest();
        test.testAdd();
        System.out.println("size of bag = " + test.b.size());
        for (String s : test.b) {
            System.out.println(s + " ");
        }
        System.out.println();

    }
}
