package org.patterns;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;

import static org.patterns.Subsets.*;

public class SubsetsTest {

    @Test
    @DisplayName("Permutation of Words")
    public void testPermuteWord() {
        String word = "bad";
        ArrayList<String> computed = permuteWord(word);
        Assertions.assertNotNull(computed);
        System.out.println(computed.toString());
        List<String> expected = new ArrayList<>(Arrays.asList("bad", "bda", "abd", "adb", "dba", "dab"));
        Assertions.assertEquals(expected.size(), computed.size());

        HashSet<String> computedSet = new HashSet<>(computed);
        HashSet<String> expectedSet  = new HashSet<>(expected);
        Assertions.assertEquals(expectedSet, computedSet);

        computed = permuteWordbyBacktracking(word);
        Assertions.assertNotNull(computed);
        System.out.println(computed.toString());
        expected = new ArrayList<>(Arrays.asList("bad", "bda", "abd", "adb", "dba", "dab"));
        Assertions.assertEquals(expected.size(), computed.size());

        computedSet = new HashSet<>(computed);
        expectedSet  = new HashSet<>(expected);
        Assertions.assertEquals(expectedSet, computedSet);
    }

    @Test
    @DisplayName("testBracketCount")
    public void testBracketCount() {
        int n;
        n = 2;
        List<String> expectedCombinations = new ArrayList<>(Arrays.asList("()()", "(())"));
        List<String> computedCombinations = generateCombinations(n);
        System.out.println(computedCombinations);
        Assertions.assertEquals(expectedCombinations.size(), computedCombinations.size());

        HashSet<String> computedSet = new HashSet<>(computedCombinations);
        HashSet<String> expectedSet  = new HashSet<>(expectedCombinations);
        Assertions.assertEquals(expectedSet, computedSet);

        n = 3;
        expectedCombinations = new ArrayList<>(Arrays.asList("()()()", "((()))", "()(())", "(())()", "(()())"));
        computedCombinations = generateCombinations(n);
        System.out.println(computedCombinations);
        Assertions.assertEquals(expectedCombinations.size(), computedCombinations.size());

        computedSet = new HashSet<>(computedCombinations);
        expectedSet  = new HashSet<>(expectedCombinations);
        Assertions.assertEquals(expectedSet, computedSet);
    }

    @Test
    @DisplayName("TestLetterCombination")
    public void testLetterCombinations() {
        String digits = "23";
        List<String> computedStrings = letterCombinations(digits);
        List<String> expectedStrings = new ArrayList<>(Arrays.asList("ad","ae", "af", "bd", "be", "bf", "cd", "ce", "cf"));
        System.out.println(computedStrings);
        Assertions.assertEquals(expectedStrings.size(), computedStrings.size());

        HashSet<String> computedSet = new HashSet<>(computedStrings);
        HashSet<String> expectedSet  = new HashSet<>(expectedStrings);
        Assertions.assertEquals(expectedSet, computedSet);

    }
}
