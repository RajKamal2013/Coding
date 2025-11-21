package org.patterns;

import org.junit.jupiter.api.Test;

public class HeapTest {
    @Test
    void testLongestDiverseString() {
        String str = Heap.longestDiverseString(3, 3, 3);
        System.out.println("String:  " + str);

        str = Heap.longestDiverseString(5, 1, 0);
        System.out.println("String:  " + str);

        str = Heap.longestDiverseString(0, 1, 0);
        System.out.println("String:  " + str);
    }

}
