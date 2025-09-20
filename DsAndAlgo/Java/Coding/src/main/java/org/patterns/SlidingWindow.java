package org.patterns;

import java.util.*;
import java.util.function.Function;
import java.util.function.IntUnaryOperator;

public class SlidingWindow {
    /*
     * Problem: Find the longest substring with non-repeating character.
     */
    public static int findLongestSubstring(String str) {
        if (str == null) {
            return  -1;
        }
        if (str.length() == 1) {
            return 1;
        }
        int firstIdx, secondIdx, len, maxLen;
        firstIdx = 0;
        len = maxLen = 1;
        secondIdx = 1;
        HashSet<Character> set = new HashSet<>();
        set.add(str.charAt(0));
        while (secondIdx < str.length()) {
            while (set.contains(str.charAt(secondIdx))) {
                len = set.size();
                maxLen = Math.max(len, maxLen);
                set.remove(str.charAt(firstIdx));
                firstIdx = firstIdx + 1;
            }
            set.add(str.charAt(secondIdx));
            secondIdx = secondIdx + 1;
        }
        len = set.size();
        maxLen = Math.max(len, maxLen);
        return maxLen;
    }

    /*
     * Problem: Find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.
     * Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
     * Output: ["AAAAACCCCC","CCCCCAAAAA"]
     */
    public static List<String> findRepeatedDnaSequences(String s) {
        Map<Long, Integer> numberEquivalentStringAtEachIdx = new HashMap<>();
        Map<Character, Long> dnaToNumMap = Map.of('A', 1L, 'C', 2L, 'G', 3L, 'T', 4L);
        final IntUnaryOperator dnaToNum = c -> {
            switch ((char) c) {
                case 'A' -> {return 1;}
                case 'C' -> {return 2;}
                case 'T' -> {return 3;}
                case 'G' -> {return 4;}
                default -> {
                    throw new IllegalArgumentException("Invalid DNA char: " + (char) c);
                }
            }
        };

        if (s == null || s.length() < 10) {
            return new ArrayList<>();
        }

        int stringIdx = 0;
        long currentEquivalent = 0;
        for (stringIdx = 0; stringIdx < 10; stringIdx++) {
            currentEquivalent = (currentEquivalent * 10L) + dnaToNum.applyAsInt(s.charAt(stringIdx));
        }

        numberEquivalentStringAtEachIdx.put(currentEquivalent, 0);
        long valueAtStartIdx;
        List<String> matchingSequence = new ArrayList<>();
        Set<String> matchingSequenceSet = new HashSet<>();
        String subString;
        for (stringIdx = 10; stringIdx < s.length(); stringIdx++) {
            System.out.println("Current Pattern: " + currentEquivalent);
            valueAtStartIdx =  (long)Math.pow(10.0, 9.0) * dnaToNum.applyAsInt(s.charAt(stringIdx - 10));
            currentEquivalent = (currentEquivalent - valueAtStartIdx) * 10 + dnaToNum.applyAsInt(s.charAt(stringIdx));
            System.out.println("Updated Pattern: " +  currentEquivalent);
            if (numberEquivalentStringAtEachIdx.containsKey(currentEquivalent)) {
                int matchedIdxAtCurrentValue = numberEquivalentStringAtEachIdx.get(currentEquivalent);
                subString = s.substring(matchedIdxAtCurrentValue, matchedIdxAtCurrentValue + 10);
               if (!matchingSequenceSet.contains(subString)) {
                   matchingSequence.add(subString);
                   matchingSequenceSet.add(subString);
               }
            } else {
                numberEquivalentStringAtEachIdx.put(currentEquivalent, stringIdx-9);
            }
        }
        System.out.println(matchingSequence.toString());
        return matchingSequence;
    }
}
