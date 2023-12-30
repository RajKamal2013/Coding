package DS.FList;

public class FlistTest {
    List<Integer> flist;

    FlistTest() {
        setUp();
    }

    public static boolean find(List<Integer> L, int k) {
        for (L.moveToStart(); L.curPos()<L.length(); L.next())
            if (k == L.getData()) return true;    // Found k
        return false;                            // k not found
    }

    public void setUp() {
        flist = new LList<Integer>();
    }

    public void testInsert() {
        System.out.println("<----------- Remove Test --------------->");
        flist.clear();
        flist.insert(1);
        flist.insert(5);
        flist.insert(10);
        flist.insert(100);
        flist.insert(200);
        System.out.println(flist);
        System.out.println();
    }

    public void testAppend() {
        System.out.println("<----------- Append Test --------------->");
        flist.clear();
        flist.append(1);
        flist.append(200);
        flist.append(300);
        flist.append(500);
        flist.append(2);
        System.out.println(flist);
        System.out.println();
    }

    public void testRemove(){
        System.out.println("<----------- Remove Test --------------->");
        flist.clear();
        flist.insert(1);
        flist.insert(2);
        flist.insert(5);
        flist.insert(20);
        flist.insert(50);
        flist.insert(100);
        System.out.println(flist);
        flist.moveToPos(3);
        int data = flist.remove();
        System.out.println(flist);
        flist.moveToStart();
        flist.remove();
        System.out.println(flist);
        System.out.println();
    }

    public void testFind(){
        System.out.println("<----------- Find Test --------------->");
        flist.clear();
        flist.insert(10);
        flist.insert(20);
        flist.insert(200);
        flist.insert(1000);
        System.out.println(flist);
        int key = 20;
        boolean ret = find(flist, 20);
        System.out.println("Data:" + key + " is present: " + ret);
        key = 900;
        ret = find(flist, 900);
        System.out.println("Data:" + key + " is present: " + ret);
    }

    public void testNext() {
        System.out.println("<----------- Next Test --------------->");

    }

    public static void main (String[] args) {
        FlistTest test = new FlistTest();
        test.testInsert();
        test.testAppend();
        test.testRemove();
        test.testFind();
    }
}
