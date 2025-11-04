package org.patterns;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertTrue;
import static org.patterns.MergeIntervals.findSets;

public class MergeIntervalsTest {
    @Test
    void testMergeInterval() {
        char[] arr = {'A','K','X','M','W','D','X','B','D','C','O','Z','D','E','Q'};
        int n = 3;

        int expected = 15;
        int actual = MergeIntervals.leastInterval(arr, n);
        assertEquals(expected, actual);
    }

    @Test
    void testMergeInterval2() {
        String[] arr = {"T", "F", "Y", "G", "R", "W", "W", "R", "S", "J", "G", "D", "A", "F", "B", "T", "L", "P", "C", "I", "R", "I", "U", "S", "U", "Q", "G", "X", "A", "H", "J", "A", "U", "C", "R", "Z", "X", "I", "S", "B", "G", "W", "N", "H", "M", "B", "R", "F", "X", "B", "N", "B", "S", "T", "Q", "M", "V", "Y", "W", "N", "E", "R", "J", "W", "U", "N", "A", "H", "F", "N", "L", "J", "Y", "B", "I", "N", "S", "L", "Y", "W", "C", "T", "P", "R", "I", "F", "E", "F", "J", "R", "B", "B", "O", "P", "G", "X", "O", "A", "P", "L", "T", "J", "R", "S", "N", "L", "I", "C", "D", "N", "O", "C", "A", "G", "I", "D", "H", "H", "G", "C", "M", "H", "P", "B", "T", "A", "P", "A", "F", "W", "J", "R", "Z", "S", "W", "O", "S", "L", "O", "S", "C", "U", "J", "W", "N", "M", "K", "S", "P", "Y", "S", "P", "J", "U", "M", "E", "S", "D", "N", "T", "G", "J", "O", "N", "E", "R", "E", "R", "J", "R", "L", "M", "G", "O", "V", "H", "M", "G", "L", "Q", "B", "Q", "K", "G", "K", "Z", "B", "P", "H", "L", "Y", "Y", "Q", "B", "P", "Q", "O", "P", "H", "G", "P", "X", "A", "V", "C", "R", "F", "I", "A", "L", "B", "D", "R", "J", "S", "F", "N", "M", "Q", "B", "N", "Y", "O", "U", "Z", "B", "M", "D", "Q", "O", "D", "A", "X", "I", "C", "O", "S", "Q", "K", "W", "V", "U", "R", "V", "W", "F", "H", "W", "B", "I", "I", "K", "A", "R", "E", "P", "A", "Y", "A", "T", "P", "N", "U", "P", "G", "I", "L", "H", "X", "G", "U", "X", "R", "Y", "P", "K", "A", "Q", "T", "E", "W", "L", "V", "R", "Z", "P", "C", "C", "D", "H", "X", "M", "G", "W", "L", "Z", "Y", "C", "X", "I", "C", "Y", "M", "M", "G", "H", "W", "O", "Q", "Z", "G", "Q", "Y", "A", "P", "J", "V", "I", "X", "Q", "Y", "A", "A", "C", "U", "X", "D", "V", "V", "J", "G", "H", "J", "N", "F", "P", "Y", "O", "C", "L", "F", "S", "B", "O", "U", "V", "Y", "K", "B", "D", "U", "G", "M", "I", "Z", "H", "J", "R", "J", "M", "D", "M", "C", "K", "C", "N", "N", "S", "F", "J", "Y", "D", "C", "M", "U", "U", "J", "M", "B", "E", "M", "U", "D", "A", "E", "Q", "M", "T", "D", "H", "K", "R", "Q", "B", "Y", "X", "S", "U", "V", "R", "X", "V", "T", "W", "L", "M", "N", "X", "M", "E", "J", "Q", "J", "H", "U", "F", "Z", "R", "E", "U", "C", "N", "G", "V", "K", "V", "K", "F", "G", "M", "X", "Y", "H", "C", "M", "D", "V", "D", "U", "Y", "R", "N", "C", "T", "S", "W", "C", "N", "H", "F", "U", "N", "A", "H", "P", "Q", "R", "Z", "W", "W", "C", "Q", "Z", "J", "D", "Z", "C", "F", "L", "O", "Y", "Z", "W", "U", "I", "R", "K", "O", "L", "T", "L", "F", "Y", "X", "O", "T", "I", "O", "H", "W", "J", "B", "I", "O", "V", "Q", "N", "C", "Y", "U", "D", "Y", "D", "H", "K", "A", "H", "A", "O", "V", "B", "Y", "D", "B", "D", "M", "A", "F", "Q", "C", "E", "Q", "Q", "V", "X", "G", "T", "P", "X", "L", "Y", "R", "G", "U", "K", "I", "V", "D", "M", "O", "K", "E", "Q", "Z", "D", "D", "C", "P", "V", "A", "I", "Z", "U", "W", "C", "P", "D", "D", "I", "L", "X", "N", "T", "D", "H", "E", "C", "Z", "P", "P", "J", "T", "Q", "G", "J", "A", "F", "U", "F", "I", "J", "D", "E", "A", "A", "B", "E", "D", "B", "A", "V", "F", "O", "A", "Q", "D", "T", "B", "P", "I", "K", "Q", "V", "N", "Y", "W", "W", "X", "G", "S", "G", "V", "U", "S", "L", "V", "D", "T", "P", "Q", "Q", "I", "E", "Z", "R", "W", "G", "E", "A", "M", "B", "B", "Z", "K", "U", "R", "N", "R", "K", "L", "J", "F", "L", "B", "N", "Z", "B", "T", "U", "N", "W", "F", "N", "T", "D", "A", "A", "J", "Z", "X", "W", "W", "A", "L", "L", "R", "D", "M", "G", "R", "E", "G", "H", "U", "C", "N", "I", "M", "C", "M", "D", "X", "J", "S", "H", "S", "T", "Y", "G", "H", "M", "C"};
        int n = 16;
        char[] charArr = new char[arr.length];
        for (int i = 0; i < arr.length; i++) {
            charArr[i] = arr[i].charAt(0); // take the first character of each String
        }
        int expected = 692;
        int actual = MergeIntervals.leastInterval(charArr, n);
        assertEquals(expected, actual);
    }
    @Test
    void testmergeIntervals() {
        int[][] intervals = {{4,6},{3,7},{1,5}};
        int[][] mergedIntervals = MergeIntervals.mergeIntervals(intervals);
        assertTrue(mergedIntervals.length >= 1);
    }

    @Test
    void testInsertInterval() {
        int[][] intervals = {{1, 3}, {5, 7}, {8, 9}, {10, 13}};
        int[] interval = {2, 6};
        int[][] expected = {{1, 7}, {8, 9}, {10, 13}};
        int[][] actual = MergeIntervals.insertInterval(intervals, interval);
        for (int[] row: actual) {
            System.out.println(row[0] + " " + row[1]);
        }
        assertTrue(actual.length == expected.length);
    }

    @Test
    void testInsertInterval1() {
        int[][] intervals = {{1,2},{3,4},{5,8},{9,15}};
        int[] interval = {2, 5};
        int[][] expected = {{1, 8}, {9, 15}};
        int[][] actual = MergeIntervals.insertInterval(intervals, interval);
        for (int[] row: actual) {
            System.out.println(row[0] + " " + row[1]);
        }
        assertTrue(actual.length == expected.length);
    }

    @Test
    void testInsertInterval2() {
        int[][] intervals = {{1,6},{8,9},{10,15},{16,18}};
        int[] interval = {9, 10};
        int[][] expected = {{1, 6}, {8, 15}, {16, 18}};
        int[][] actual = MergeIntervals.insertInterval(intervals, interval);
        for (int[] row: actual) {
            System.out.println(row[0] + " " + row[1]);
        }
        assertTrue(actual.length == expected.length);
    }

    @Test
    void testMeetingRooms() {
        int[][] intervals = {{2, 8}, {3, 4}, {3, 9}, {5, 11}, {8, 20}, {11, 15}};
        int meetingRoomCount = findSets(intervals);
        int expected = 3;
        assertEquals(expected, meetingRoomCount);
    }


}
