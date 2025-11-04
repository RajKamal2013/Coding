package org.patterns;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.PriorityQueue;

public class MergeIntervals {

    /**
     * You are given a character array tasks, where each character represents a unique task.
     * You also have a cooling time n, which is the minimum number of idle intervals required
     * between two identical tasks.
     * The CPU can perform one task per interval or be idle.
     * The goal is to return the least number of intervals to complete all tasks.
     * Input: tasks = ["A", "A", "A", "B", "B", "B"], n = 2
     * Output: 8
     * Explanation: A valid schedule is A -> B -> idle -> A -> B -> idle -> A -> B
     */
    public static int leastInterval(char[] tasks, int n) {
            if (tasks == null) {
                return -1;
            }
            if (tasks.length == 0) {
                return 0;
            }
            if (tasks.length == 1) {
                return 1;
            }

            int[] charFreq = new int[26];
            Arrays.fill(charFreq, 0);
            for (char ch : tasks) {
                charFreq[ch - 'A'] = charFreq[ch - 'A'] + 1;
            }
            Arrays.sort(charFreq);
            System.out.println(Arrays.toString(charFreq));
            int taskRemaining = tasks.length;
            int time = 0;
            int intervalCount = -1;
            while (taskRemaining > 0) {
                intervalCount = -1;
                for (int i = 25; i >= 0; i--) {
                    if (charFreq[i] > 0) {
                        time = time + 1;
                        intervalCount = intervalCount + 1;
                        charFreq[i] = charFreq[i] - 1;
                        taskRemaining--;
                        if (intervalCount == n) {
                            break;
                        }
                    }
                }
                if ((intervalCount < n) && (taskRemaining > 0)) {
                    time = time + (n - intervalCount);
                }
                Arrays.sort(charFreq);
            }
            return time;
    }


    /**
     * Merge overlapping intervals.
     */
    public static int[][] mergeIntervals(int[][] intervals) {
        if (intervals == null) {
            return new int[][]{};
        }
        if (intervals.length == 1) {
            return intervals;
        }

        int intervalsCount = intervals.length;
        List<int[]> mergedInterval = new ArrayList<>();
        PriorityQueue<int[]> minHeap = new PriorityQueue<>(
                (a, b) -> {
                    if (a == b) return 0;
                    return Integer.compare(a[0], b[0]);
                }
        );

        for (int[] row: intervals) {
            minHeap.offer(row);
        }

        while (minHeap.size() >= 2) {
            int[] firstInterval = minHeap.poll();
            int[] secondInterval = minHeap.peek();
            if (firstInterval != null && secondInterval != null) {
                if (firstInterval[1] >= secondInterval[0]) {
                    minHeap.poll();
                    int start = firstInterval[0];
                    int end = Math.max(firstInterval[1], secondInterval[1]);
                    int[][] merged = new int[1][2];
                    merged[0][0] = start;
                    merged[0][1] = end;
                    minHeap.offer(merged[0]);
                } else {
                    mergedInterval.add(firstInterval);
                }
            }
        }
        mergedInterval.add(minHeap.poll());

        return mergedInterval.toArray(new int[mergedInterval.size()][]);
    }

    /**
     *
     * You are given a list of non-overlapping intervals, intervals, where each interval is
     * represented as [starti, endi] and the list is sorted in ascending order by the start of each interval (starti).
     * You are also given another interval, newInterval = [start, end].
     * Your task is to insert newInterval into the list of intervals such that the list remains sorted by
     * starting times and still contains no overlapping intervals. If any intervals overlap after the insertion,
     * merge them accordingly.
     *
     * Return the updated list of intervals.
     * @param existingIntervals
     * @param newInterval
     * @return int[][], non overlapping intervals  including existingIntervals and newInterval.
     */
    public static int[][] insertInterval1(int[][] existingIntervals, int[] newInterval) {
        if (existingIntervals == null || existingIntervals.length == 0) {
            return new int[][]{};
        }
        List<int[]> nonOverlappingIntervals = new ArrayList<>();
        int idx = 0;
        boolean intervalNotMerged = true;
        while (intervalNotMerged) {
            if ((existingIntervals[idx][0] <= newInterval[0]) &&
                    (existingIntervals[idx][1] >= newInterval[0])) {
                int start = Math.min(existingIntervals[idx][0], newInterval[0]);
                int end = Math.max(existingIntervals[idx][1], newInterval[1]);
                if (end > existingIntervals[idx][1]) {
                    while (idx < existingIntervals.length && existingIntervals[idx][0] <= end) {
                        idx = idx + 1;
                    }
                    end = Math.max(existingIntervals[idx - 1][1], end);
                }
                int[] interval = new int[2];
                interval[0] = start;
                interval[1] = end;
                nonOverlappingIntervals.add(interval);
            } else {
                nonOverlappingIntervals.add(existingIntervals[idx]);
                idx = idx + 1;
            }
            if (idx == existingIntervals.length) {
                intervalNotMerged = false;
            }
        }
        if (newInterval[0] > existingIntervals[idx -1][0]) {
            nonOverlappingIntervals.add(newInterval);
        }
        return nonOverlappingIntervals.toArray(new int[nonOverlappingIntervals.size()][]);
    }

    /**
     * Given list of intervals, find out how many meeting rooms will be needed.
     * @param intervals, list of intervals
     * @return number of meeting rooms needed.
     * Example: {[2, 8], [3, 4], [3, 9], [5, 11], [8, 20], [11, 15]}
     * Answer: 3
     */
    public static int findSets(int[][] intervals) {
        if (intervals == null || intervals.length == 0) {
            return 0;
        }
        if (intervals.length == 1) { return 1;}

        int meetingRooms = 0;
        Arrays.sort(intervals, (a, b) -> {return Integer.compare(a[0], b[0]);});
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        meetingRooms = 1;
        minHeap.offer(intervals[0][1]);
        int nextAvailableRoom;
        for (int i = 1; i < intervals.length; i++) {
            nextAvailableRoom = minHeap.peek();
            if (intervals[i][0] < nextAvailableRoom) {
                meetingRooms = meetingRooms + 1;
            } else {
                minHeap.poll();
            }
            minHeap.offer(intervals[i][1]);
        }
        return meetingRooms;
    }


    // This code has issue
    public static int[][] insertInterval(int[][] existingIntervals, int[] newInterval) {
        if (existingIntervals == null || existingIntervals.length == 0) {
            return new int[][]{};
        }

        int[][] newIntervals = new int[existingIntervals.length + 1][2];
        int idx = 0;
        if (existingIntervals[idx][0] > newInterval[1]) {
            newIntervals[idx] = newInterval;
            for (int i = idx; i < existingIntervals.length; i++) {
                newIntervals[i + 1]   = existingIntervals[i];
            }
            return newIntervals;
        }

        List<int[]> mergedIntervals = new ArrayList<>();
        while ((idx < existingIntervals.length) &&
                (existingIntervals[idx][0] < newInterval[0]) &&
                (existingIntervals[idx][1] < newInterval[0])) {
            mergedIntervals.add(existingIntervals[idx]);
            idx = idx + 1;
        }
        if (idx == existingIntervals.length) {
            mergedIntervals.add(newInterval);
            return mergedIntervals.toArray(new int[mergedIntervals.size()][]);
        }

        boolean merged = false;
        if (newInterval[0] > existingIntervals[idx][1]) {
            mergedIntervals.add(newInterval);
            merged = true;
        }
        int start = Math.min(newInterval[0], existingIntervals[idx][0]);
        int end = Math.max(newInterval[1], existingIntervals[idx][1]);
        if (end == existingIntervals[idx][1]) {
            merged = true;
        }
        idx = idx + 1;
        if (idx == existingIntervals.length) {
            merged = true;
            int[] mergedInterval = new int[2];
            mergedInterval[0] = start;
            mergedInterval[1] = end;
            mergedIntervals.add(mergedInterval);
        }
        while (!merged) {
            if (newInterval[1] >= existingIntervals[idx][0]) {
                end = Math.max(newInterval[1], existingIntervals[idx][1]);
                idx = idx + 1;
                if (idx == existingIntervals.length) {
                    merged = true;
                    int[] mergedInterval = new int[2];
                    mergedInterval[0] = start;
                    mergedInterval[1] = end;
                    mergedIntervals.add(mergedInterval);
                }
            } else {
                merged = true;
                int[] mergedInterval = new int[2];
                mergedInterval[0] = start;
                mergedInterval[1] = end;
                mergedIntervals.add(mergedInterval);
            }
        }


        for (int i = idx; i < existingIntervals.length; i++) {
           mergedIntervals.add(existingIntervals[i]);
        }
        return mergedIntervals.toArray(new int[mergedIntervals.size()][]);
    }

}
