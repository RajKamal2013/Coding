package org.project.functional;

import java.util.ArrayList;
import java.util.List;
import java.util.function.BiFunction;

import java.util.function.Function;
import java.util.function.Predicate;
import java.util.stream.Collectors;

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

    public static void main(String[] args) {
        Basic basic = new Basic();
        basic.testBasicMap();
    }
}
