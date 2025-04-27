package org.core.collections.hashSet;

import java.util.*;

public class HashSetDemo {
    public static void main(String args[]) {
        Set<Integer> set = new HashSet<>();
        System.out.println(set.isEmpty());

        set.add(23);
        set.add(34);
        set.add(56);
        System.out.println(set.isEmpty());

        System.out.println(set.contains(23));

        Iterator<Integer> itr = set.iterator();

        while(itr.hasNext()) {
            System.out.println(itr.next());
        }

        for(int i : set) {
            System.out.println(i);
        }

        set.forEach(System.out::println);

        // Creating an ArrayList from existing set.
        List<Integer> list = new ArrayList<>(set);
        // Sorting the list.
        Collections.sort(list);

        list.forEach(System.out::println);


        set.remove(23);

        System.out.println("HashSet after removing one element" + set);

        set.clear();
        System.out.println(set.isEmpty());

        System.out.println("HashSet after removing all elements" + set);

    }

}
