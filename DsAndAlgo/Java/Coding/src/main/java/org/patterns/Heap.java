package org.patterns;

import java.util.Arrays;
import java.util.Collections;
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
}
