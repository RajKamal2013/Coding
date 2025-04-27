package org.core.collections.treeSet;

import java.util.TreeSet;

public class TreeSetDemo {
    public static void main(String args[]) {

        TreeSet<Integer> set = new TreeSet<>();
        set.add(21);
        set.add(32);
        set.add(44);
        set.add(11);
        set.add(54);
        set.add(3);
        set.add(9);
        set.add(41);

        System.out.println("Fetching the first element in TreeSet " + set.first());
        System.out.println("Fetching the last element in TreeSet " + set.last());
        System.out.println("Fetching all the elements less than 40 " + set.headSet(40));
        System.out.println("Fetching all the elements greater than 40 " + set.tailSet(40));

        System.out.println("Checking if TreeSet is empty: " + set.isEmpty());
        System.out.println("Checking the TreeSet size: " + set.size());
        System.out.println("Checking if TreeSet contains 44: " + set.contains(44));

        System.out.println("Removing 44 from TreeSet " + set.remove(44));
        System.out.println("Removing 100 from TreeSet " + set.remove(100));





    }
}
