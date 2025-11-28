package org.patterns;

import java.util.Arrays;

public class GreedyAlgorithm {

    public static boolean jumpBacktracking(int[] nums, int currentIdx) {
        if (currentIdx >= nums.length-1) {
            return true;
        }
        if (nums[currentIdx] == 0) {
            return false;
        }

        boolean ret = false;
        int nextIdx = 0;

        for (int i = nums[currentIdx]; i >= 1; i--) {
            nextIdx = currentIdx + i;
            ret = jumpBacktracking(nums, nextIdx);
            if (ret) {
                break;
            }
        }
        return ret;
    }

    public static boolean jumpGameSubOptimal(int[] nums) {
        if (nums == null || nums.length == 0) { return true; }
        if (nums.length == 1) { return true; }
        boolean ret = jumpBacktracking(nums, 0);
        return ret;
    }

    /* See if jumping based on value of idx at nums, end of num is reachable */
    public static boolean jumpGame(int[] nums) {
        if (nums == null || nums.length == 0) { return false; }
        if (nums.length == 1) { return true; }
        int maxIdxReachable = 0;
        boolean ret = false;
        for (int i = 0; i < nums.length; i++) {
            if (i > maxIdxReachable) { break; }
            maxIdxReachable = Math.max(maxIdxReachable, i + nums[i]);
            if (maxIdxReachable >= nums.length - 1) { ret = true; break;}
        }
        return ret;
    }

    public static int jumpGame2(int[] nums) {
        if (nums == null || nums.length == 0) { return 0; }
        if (nums.length == 1) { return 0; }
        int maxIdxReachable = 0;
        int minStepsTakenToReachIdx = 0;
        int currentIdx = 0;
        for (int i = 0; i < nums.length - 1; i++) {
            maxIdxReachable = Math.max(maxIdxReachable, i + nums[i]);
            if (i == currentIdx) {
                minStepsTakenToReachIdx = minStepsTakenToReachIdx + 1;
                currentIdx = maxIdxReachable;
            }
        }
        return minStepsTakenToReachIdx;
    }

    public static int gasStationJourney(int[] gas, int[] cost) {

        if (gas == null || cost == null || gas.length == 0 || cost.length == 0) { return  -1;}

        if (gas.length != cost.length) { return -1; }
        int gasAvailable = Arrays.stream(gas).sum();
        int gasConsumed = Arrays.stream(cost).sum();

        if (gasConsumed > gasAvailable) { return -1; }
        int maxGasAvailableAfterConsumption = 0;
        int startIdx = -1;
        int gasSurplus = 0;
        for (int i = 0; i < gas.length; i++) {
            int gasAvailableAfterConsumption = gas[i] - cost[i];
            gasSurplus = gasSurplus + gasAvailableAfterConsumption;
            if (gasAvailableAfterConsumption < 0) {
                continue;
            }
            if (maxGasAvailableAfterConsumption <= gasSurplus) {
                startIdx = i;
                maxGasAvailableAfterConsumption = gasSurplus;
            }
        }
       return startIdx;
    }
}

