package org.patterns;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

import static org.patterns.KTopElement.reorganizeString;
import static org.patterns.KTopElement.topKFrequent;

public class KTopElementTest {

    @Test
    @DisplayName("KTopFrequentElement")
    public void testKTopFrequentElement() {
        int[] arr = {1, 3, 5, 14, 18, 14, 5};
        int k = 2;

        List<Integer> expectedList = Arrays.asList(5, 14);
        List<Integer> computedList = topKFrequent(arr, k);
        Assertions.assertEquals(expectedList.size(), computedList.size());

        Set<Integer> expectedSet = new HashSet<>(expectedList);
        Set<Integer> computedSet = new HashSet<>(computedList);
        System.out.printf("Expected : %s\n", expectedSet.toString());
        System.out.printf("Computed: %s\n", computedSet.toString());
        Assertions.assertEquals(expectedSet, computedSet);


        arr = new int[]{1, 1, 1, 3, 3, 4, 5};
        k = 1;
        expectedList = Arrays.asList(1);
        computedList = topKFrequent(arr, k);
        Assertions.assertEquals(expectedList.size(), computedList.size());

        expectedSet = new HashSet<>(expectedList);
        computedSet = new HashSet<>(computedList);
        System.out.printf("Expected : %s\n", expectedSet.toString());
        System.out.printf("Computed: %s\n", computedSet.toString());
        Assertions.assertEquals(expectedSet, computedSet);
    }

    @Test
    @DisplayName("Test reorganizeString")
    public void testReorganizeString() {
        String str = "";
        String expectedString = "";
        String computedString = "";
        Set<Character> expectedStringSet = new HashSet<>();
        Set<Character> computedStringSet = new HashSet<>();


        str = "aaabc";
        expectedString = "abaca";
        computedString = reorganizeString(str);
        expectedStringSet.clear();
        computedStringSet.clear();
        expectedString.chars().forEach(c -> expectedStringSet.add((char)c));
        computedString.chars().forEach(c -> computedStringSet.add((char)c));
        Assertions.assertEquals(expectedString.length(), computedString.length());


        str = "aaaac";
        expectedString = "";
        computedString = reorganizeString(str);
        expectedStringSet.clear();
        computedStringSet.clear();
        Assertions.assertEquals(expectedString.length(), computedString.length());
       // expectedString.chars().forEach(c -> expectedStringSet.add((char)c));
       // computedString.chars().forEach(c -> computedStringSet.add((char)c));

    }
}
