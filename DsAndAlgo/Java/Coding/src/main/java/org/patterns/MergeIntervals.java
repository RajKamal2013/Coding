package org.patterns;

import java.util.Arrays;

public class MergeIntervals {

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

}
