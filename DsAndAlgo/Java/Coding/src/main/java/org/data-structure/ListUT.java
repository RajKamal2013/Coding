package DS;

import java.util.PrimitiveIterator;
import java.util.stream.IntStream;

public class ListUT {

    public static void main(String[] args) {
            SLL<Integer> list = new SLL<Integer> ();
            int i = 0;
            IntStream stream = IntStream.range(1, 99);
            PrimitiveIterator.OfInt answer = stream.iterator();
            while (answer.hasNext()) {
                list.append(answer.nextInt());
            }
            System.out.println("List :");
            System.out.println(list.toString());
            list.reverse();
            System.out.println(list.toString());
            list.reverse();
            System.out.println(list.toString());
            int data = 96;
            boolean res = list.contains(96);
            String strRes = (res == true) ? " ": "not";
            System.out.println(data + " is " + strRes +  "present in list");
            list.remove(96);
            res = list.contains(96);
            strRes = (res == true) ? " ": "not";
            System.out.println(list.toString());
            System.out.println(data + " is " + strRes +  "present in list");
    }
}
