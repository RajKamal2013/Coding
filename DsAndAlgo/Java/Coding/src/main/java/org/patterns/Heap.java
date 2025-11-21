package org.patterns;

import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.PriorityQueue;

public class Heap {

    /**
     * Tasks = int[][]
     * Tasks[i] = [Starti , Endi]
     * Minimum number needed to complete all the tasks. No machine can execute more than one task at a time
     * Machine can start executing as soon as task complete.
     * @param tasks, array of tasks.
     * @return number of machine needed
     */
    public static int minimumMachines(int[][] tasks) {
        if(tasks == null || tasks.length == 0) { return 0; }
        if (tasks.length == 1) { return 1; }
        Arrays.sort(tasks, (a, b) ->  Integer.compare(a[0], b[0]));
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        int machineCount = 0;

        minHeap.offer(tasks[0][1]);
        machineCount = 1;

        int nextAvailableSlot = 0;
        for(int i = 1; i < tasks.length; i++) {
            nextAvailableSlot = minHeap.peek();
            if (tasks[i][0] < nextAvailableSlot) {
                machineCount = machineCount + 1;
            } else {
                minHeap.poll();
            }
            minHeap.offer(tasks[i][1]);
        }

        return machineCount;
    }

    public static int connectSticks (int[] sticks) {
        if (sticks == null || sticks.length == 0) {
            return 0;
        }
        if (sticks.length == 1) {
            return 0;
        }

        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        for (int stick: sticks) {
            minHeap.offer(stick);
        }

        int cost  =  0;
        while(minHeap.size() >= 2) {
            int stick1 = minHeap.poll();
            int stick2 = minHeap.poll();

            int combinedStick = stick1 + stick2;
            cost = cost + combinedStick;
            minHeap.offer(combinedStick);
        }

        //minHeap.poll();

        return cost;
    }

    static class Pair {
        int count;
        char ch;
        Pair(int count, char ch) {
            this.ch = ch;
            this.count = count;
        }
    }
    public static String longestDiverseString(int a,  int b, int c) {
        PriorityQueue<Pair> maxHeap = new PriorityQueue<>((p1, p2) -> p2.count - p1.count);
        if (a > 0) maxHeap.offer(new Pair(a, 'a'));
        if (b > 0) maxHeap.offer(new Pair(b, 'b'));
        if (c > 0) maxHeap.offer(new Pair(c, 'c'));

        StringBuilder stringBuilder = new StringBuilder();

        while (!maxHeap.isEmpty()) {
            Pair maxFreqChar = maxHeap.poll();
            int len = stringBuilder.length();
            if (len >= 2 && stringBuilder.charAt(len - 2) == maxFreqChar.ch && stringBuilder.charAt(len - 1) == maxFreqChar.ch) {
                if (maxHeap.isEmpty()) { break;}
                Pair nextFreqChar = maxHeap.poll();
                stringBuilder.append(nextFreqChar.ch);

                if (--nextFreqChar.count > 0) maxHeap.add(nextFreqChar);

                maxHeap.offer(maxFreqChar);
            } else {
                stringBuilder.append(maxFreqChar.ch);
                if(--maxFreqChar.count > 0) maxHeap.add(maxFreqChar);
            }
        }
        return stringBuilder.toString();
    }
}
