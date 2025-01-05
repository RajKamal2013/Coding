package org.project.functional;

import javax.sound.midi.Soundbank;
import java.util.ArrayList;
import java.util.List;
import java.util.function.BiFunction;

import java.util.function.BiPredicate;
import java.util.function.Function;
import java.util.function.Predicate;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class Basic {

    public void testBasicMap() {
        List<Integer> mappedList = new ArrayList<>();
        for (int i = 0; i < 20; i++) {
            mappedList.add(i);
        }
        System.out.println("Original List: "+ mappedList.toString());

        List<Integer> list2 = mappedList.stream().map(item -> item * item).toList();
        System.out.println("Modified List: "+ list2.toString());

        List<Integer> list3 = mappedList.stream().map(item -> item * 4).toList();
        System.out.println("Modified List: "+ list3.toString());

        List<Integer> tempList = mappedList.stream().map(item -> item * 10).map(item -> item + 10).toList();
        System.out.println("Intermediate List :" + tempList.toString());
        List<Integer> list4 = mappedList.stream().map(item -> item *10).map(item -> item + 10).filter(item -> item > 40).toList();
        System.out.println("Chaining List: " + list4.toString());

        BiFunction<Integer, Integer, Integer> addFunction = (a, b) -> {return a + b;};
        Function<Integer, Integer> multiplyFunction = (a) -> {return a * 2;};

        System.out.println(multiplyFunction.apply(addFunction.apply(2,3)));

        Predicate<Integer> predicate =i -> i > 10;
        for (int i: mappedList) {
            System.out.println("Value greater than 10: "+ predicate.test(i));
        }

        List<Integer> filteredList = mappedList.stream().filter(val -> predicate.test(val)).collect(Collectors.toUnmodifiableList());
        System.out.println("Filtered LIST: " + filteredList.toString() );
    }

    public static void defaultFunctionalMethods() {
        List<String> nameString = new ArrayList<>();
        nameString.add("HI");
        nameString.add("Hello");
        nameString.add("Yes");
        nameString.add("No");
        nameString.add("Excuse");
        nameString.add("Print");
        nameString.add("Delete");
        nameString.add("Updated");
        nameString.add("Database");
        nameString.add("Os");
        nameString.add("Apple");
        nameString.add("Linux");
        nameString.add("Windows");

        BiPredicate<Integer, Integer> greaterThanVar = (item, var) -> item > var;
        int fixedVar = 6;
        List<Integer> intList = nameString.stream()
                .map(item -> item.length())
                .filter(item-> greaterThanVar.test(item,fixedVar))
                .collect(Collectors.toList());

         Stream<String> updatedStream = nameString.stream()
                 .filter(item-> item.length()>5)
                 .map(item->item.toUpperCase());

         updatedStream.forEach(System.out::println);
        for (int item: intList) {
            System.out.println("Item: " + item);
        }
    }
    public static void main(String[] args) {
        //Basic basic = new Basic();
        //basic.testBasicMap();
        defaultFunctionalMethods();
    }
}
