package org.patterns;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

import java.util.HashSet;
import java.util.List;
import java.util.Set;

import static org.patterns.Backtracking.restoreIpAddresses;
import static org.patterns.Backtracking.wordSearch;

public class BacktrackingTest {

    @Test
    @DisplayName("Test BackTracking")
    public void testWordSearch() {
        char[][] grid = {
                {'E', 'D', 'X', 'I', 'W'},
                {'P', 'U', 'F', 'M', 'Q'},
                {'I', 'C', 'A', 'T', 'E'},
                {'M', 'A', 'L', 'C', 'A'},
                {'J', 'T', 'I', 'V', 'E'}
        };
        String word = "EDUCATIVE";
        boolean calculated = true;
       // calculated = wordSearch(grid, word);
       // Assertions.assertTrue(calculated);

        System.out.println();
        System.out.println();
        word = "PUCAT";
        //calculated = wordSearch(grid, word);
       // Assertions.assertTrue(calculated);

        grid = new char[][]{
                {'C', 'S', 'S', 'A', 'M'},
                {'O', 'I', 'L', 'L', 'O'},
                {'O', 'L', 'I', 'T', 'O'},
                {'R', 'T', 'A', 'S', 'N'},
                {'S', 'I', 'T', 'A', 'C'}
        };
        word = "SALT";
        calculated = wordSearch(grid, word);
        Assertions.assertTrue(calculated);
    }

    @Test
    @DisplayName("Valid IP Addresses")
    public  void testRestoreIpAddresses() {
        String str;
        List<String> expected = null;
        List<String> computed = null;
        Set<String> expectedSet = null;
        Set<String> computedSet= null;

        str = "010010";
        expected = List.of("0.10.0.10","0.100.1.0");
        expectedSet = new HashSet<>(expected);
        computed = restoreIpAddresses(str);
        System.out.println("Expected: " + expected);
        computedSet = new HashSet<>(computed);
        System.out.println("Computed: " + computed);
        Assertions.assertEquals(expected.size(), computed.size());
        Assertions.assertEquals(expectedSet, computedSet);
    }
}
