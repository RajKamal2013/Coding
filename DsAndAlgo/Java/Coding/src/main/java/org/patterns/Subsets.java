package org.patterns;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

public class Subsets {

    /* Return all the permutations of word. */
    public static ArrayList<String> permuteWord(String word) {
        if (word == null || word.isEmpty()) {
            return new ArrayList<>();
        }

        ArrayList<String> permutations = new ArrayList<>();
        if (word.length() == 1) {
            permutations.add(word);
            return permutations;
        }

        // Add empty string
        permutations.add("");
        ArrayList<String> intermediatePermutations = new ArrayList<>();
        for (char ch: word.toCharArray()) {
            intermediatePermutations.clear();

            for (String str: permutations) {
                if (str.isEmpty()) {
                    intermediatePermutations.add(String.valueOf(ch));
                    continue;
                }
                if (str.length() == 1) {
                    intermediatePermutations.add(str + ch);
                    intermediatePermutations.add(ch + str);
                    continue;
                }

                intermediatePermutations.add(ch + str);
                intermediatePermutations.add(str + ch);

                for(int i = 0; i < str.length() - 1; i++) {
                    intermediatePermutations.add(str.substring(0, i + 1) + ch +
                            str.substring(i + 1));
                }
            }
            permutations = new ArrayList<>(intermediatePermutations);
        }

        return permutations;
    }

    public static ArrayList<String> permuteWordbyBacktracking(String word) {
        if (word == null || word.isEmpty()) {
            return new ArrayList<>();
        }

        ArrayList<String> permutations = new ArrayList<>();
        if (word.length() == 1) {
            permutations.add(word);
            return permutations;
        }

        boolean[] used = new boolean[word.length()];
        StringBuilder current = new StringBuilder();
        List<String> intermediatePermutations = new ArrayList<>();
        permutationsByBacktracking(word, current, used, intermediatePermutations);
        return new ArrayList<>(intermediatePermutations);
    }

    public static void permutationsByBacktracking(String word, StringBuilder current, boolean[] used, List<String> permutations) {
        if (current.length() == word.length()) {
            permutations.add(current.toString());
            return;
        }
        for (int i = 0; i < word.length(); i++) {
            if (used[i]) continue;
            used[i] = true;
            current.append(word.charAt(i));
            permutationsByBacktracking(word, current, used, permutations);
            current.deleteCharAt(current.length() - 1);
            used[i] = false;
        }
    }

    public static ArrayList<String> generateCombinations(int n) {
        if (n == 0 ) {
            return new ArrayList<>();
        }

        ArrayList<String> result = new ArrayList<String>();

        if (n == 1) {
            result.add("()");
            return result;
        }

        StringBuilder current = new StringBuilder();
        backtrackingForGenerateCombinations(n, current, 0, 0, result);
        return result;
    }

    public static void backtrackingForGenerateCombinations(int number, StringBuilder current, int openCount,  int closeCount,
                                                           List<String> permutations) {

        if (openCount == number && closeCount == number) {
            permutations.add(current.toString());
            return;
        }

        if (openCount  < number) {
            current.append("(");
            backtrackingForGenerateCombinations(number, current, openCount + 1, closeCount, permutations);
            current.deleteCharAt(current.length() - 1);
        }

        if (closeCount < openCount) {
            current.append(")");
            backtrackingForGenerateCombinations(number, current, openCount, closeCount + 1, permutations);
            current.deleteCharAt(current.length()  - 1);
        }
    }

    public static List<String> letterCombinations(String digits){
        if (digits == null || digits.isEmpty()) {
            return new ArrayList<>();
        }
        int limit = 0;
        int digit = Integer.parseInt(digits);
        while (digit > 0) {
            limit++;
            digit = digit/10;
        }

        Character[][] arr = new Character[limit][];
        int count = 0;
        for (Character ch: digits.toCharArray()) {
            switch (ch) {
                case '2' -> arr[count] = new Character[]{'a', 'b', 'c'};
                case '3' -> arr[count] = new Character[]{'d', 'e', 'f'};
                case '4' -> arr[count] = new Character[]{'g', 'h', 'i'};
                case '5' -> arr[count] = new Character[]{'j', 'k', 'l'};
                case '6' -> arr[count] = new Character[]{'m', 'n', 'o'};
                case '7' -> arr[count] = new Character[]{'p', 'q', 'r', 's'};
                case '8' -> arr[count] = new Character[]{'t', 'u', 'v'};
                case '9' -> arr[count] = new Character[]{'w', 'x', 'y', 'z'};
                default ->  arr[count] = new Character[]{};
            }
            count = count + 1;
        }
        StringBuilder curr = new StringBuilder();
        List<String> permutations = new ArrayList<>();
        backtrackingForLetterCombinations(limit, arr, curr, 0, permutations);

        return permutations;
    }

    public static void backtrackingForLetterCombinations(int limit, Character[][] arr, StringBuilder current,
                                                         int arrIdx, List<String> permutations) {

        if (current.length() == limit) {
            permutations.add(current.toString());
            return;
        }
        if (arrIdx >= limit) { return;}


        for (int idx = 0; idx < arr[arrIdx].length; idx++) {
            current.append(arr[arrIdx][idx]);
            backtrackingForLetterCombinations(limit, arr, current, arrIdx + 1, permutations);
            current.deleteCharAt(current.length() - 1);
        }
    }
}
