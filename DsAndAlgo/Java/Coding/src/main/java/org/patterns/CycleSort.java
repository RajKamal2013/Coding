package org.patterns;

public class CycleSort {
    public static int firstMissingPositiveInteger(int[] nums) {
        if (nums == null || nums.length == 0) { return -1; }

        int posOfIdx = -1;
        int idx = 0;
        while (idx < nums.length) {
            if (nums[idx] <= 0 && nums[idx] > nums.length) {
                idx = idx + 1;
            }
            posOfIdx = nums[idx] - 1;
            if (posOfIdx < 0 || posOfIdx >= nums.length) {
                idx = idx + 1;
                continue;
            }
            if (posOfIdx != idx && (nums[idx] != nums[posOfIdx])) {
                int temp = nums[posOfIdx];
                nums[posOfIdx] = nums[idx];
                nums[idx] = temp;
            } else {
                idx = idx + 1;
            }
        }
        int expectedValue = 1;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == expectedValue) { expectedValue = expectedValue + 1;}
        }
        // Replace this placeholder return statement with your code
        return expectedValue;
    }

    public static int findMissingNumber(int[] arr) {

        if (arr == null || arr.length == 0) {
            return 0;
        }

        int idx = 0;
        int pos = -1;
        while (idx < arr.length) {
            if (arr[idx] == 0) { idx = idx + 1; }
            pos = arr[idx] - 1;
            if (arr[pos] != arr[idx]) {
                int temp = arr[pos];
                arr[pos] = arr[idx];
                arr[idx] = temp;
            } else {
                idx = idx + 1;
            }
        }

        int missingNum = -1;
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] != i + 1) {
                missingNum = i + 1;
                break;
            }
        }
        return missingNum;
    }

    public static int[] findCorruptPair(int[] nums) {
        int index = 0;
        int valueAtIndex = 0;
        int correctIndex = 0;
        int correctIndexForValue = 0;
        while (index < nums.length) {
            valueAtIndex = nums[index];
            correctIndexForValue = valueAtIndex - 1;
            if (index != correctIndexForValue) {
                if (correctIndexForValue >= 0 && nums[index] == nums[correctIndexForValue]) {
                    index = index + 1;
                } else {
                    swap(nums, index, correctIndexForValue);
                }
            } else {
                index = index + 1;
            }
        }

        int missing, duplicate;
        missing = duplicate = -1;
        for (int i = 0; i < nums.length; i++) {
            if (i != nums[i] - 1) {
                missing = i + 1;
                duplicate = nums[i];
            }
        }
        return new int[] {missing, duplicate};
    }

    public static void swap(int[] arr, int idx1, int idx2) {
        int temp = arr[idx1];
        arr[idx1] = arr[idx2];
        arr[idx2] = temp;
    }

    public static int[] sortArrayByParityII (int[] nums)
    {
        if (nums == null) {
            return new int[0];
        }

        int evenIdx, oddIdx, idx;
        idx = 0;
        evenIdx = 0;
        oddIdx = 1;

        while (idx < nums.length) {
            if ((idx % 2 == 0) && (nums[idx] % 2 == 0)) {
                evenIdx = idx + 2;
                idx = idx + 1;
            } else if ((idx % 2 == 1) && (nums[idx] % 2 == 1)) {
                oddIdx = idx + 2;
                idx = idx + 1;
            } else {
                if ((idx % 2 == 0) && (oddIdx < nums.length)) {
                    swap(nums, idx, oddIdx);
                    oddIdx = oddIdx + 2;
                }
                if ((idx % 2 == 1) && (evenIdx < nums.length)) {
                    swap(nums, idx, evenIdx);
                    evenIdx = evenIdx + 2;
                }
            }
        }
        return nums;
    }

}
