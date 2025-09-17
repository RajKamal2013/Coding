package org.patterns;

import java.util.HashSet;

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
}
