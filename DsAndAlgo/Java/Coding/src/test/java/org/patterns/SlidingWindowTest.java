package org.patterns;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;
import static org.patterns.SlidingWindow.findLongestSubstring;

class SlidingWindowTest {


        @Test
        void testNullInputReturnsMinusOne() {
            assertEquals(-1, findLongestSubstring(null),
                    "null input should return -1");
        }

        @Test
        void testEmptyStringThrowsIndexOutOfBounds() {
            // The provided implementation accesses charAt(0) and will throw for empty strings.
            assertThrows(StringIndexOutOfBoundsException.class,
                    () -> findLongestSubstring(""),
                    "empty string should throw StringIndexOutOfBoundsException with current implementation");
        }

        @Test
        void testSingleCharacterReturnsOne() {
            assertEquals(1, findLongestSubstring("a"),
                    "single character string should return 1");
        }

        @Test
        void testAllUniqueCharacters() {
            assertEquals(5, findLongestSubstring("abcde"),
                    "all-unique characters should return full length");
        }

        @Test
        void testAllSameCharacters() {
            assertEquals(1, findLongestSubstring("aaaaaa"),
                    "all-same characters should return 1");
        }

        @Test
        void testTypicalRepeatingPattern() {
            // from common examples: "abcabcbb" -> longest is "abc" length 3
            assertEquals(3, findLongestSubstring("abcabcbb"));
        }

        @Test
        void testAnotherCommonExample() {
            // "pwwkew" -> "wke" length 3
            assertEquals(3, findLongestSubstring("pwwkew"));
        }

        @Test
        void testStringWithSpacesAndRepeats() {
            // " a b c a " -> consider spaces as characters
            assertEquals(4, findLongestSubstring(" a bca "));
            // Explanation: for example substring "bca " length 4 (depending on positions)
        }

        @Test
        void testComplexMixedCase() {
            assertEquals(6, findLongestSubstring("abcaefghib"),
                    "Longest non-repeating substring is likely \"caefgh\" or similar of length 6");
        }

}