package org.patterns;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

import java.util.Arrays;

public class CycleSortTest {

    @Test
    @DisplayName("Test sortArrayByParityII")
    public void testSortArrayByParityII() {
        int[] nums = {3, 2, 1, 4};

        nums = CycleSort.sortArrayByParityII(nums);

        System.out.println(Arrays.toString(nums));

        for (int idx = 0; idx < nums.length; idx++) {
            var valueAtIdx = nums[idx];
            if (idx % 2 == 0) {
                Assertions.assertEquals(0, nums[idx] % 2);
            } else {
                Assertions.assertEquals(1, nums[idx] % 2);
            }
        }

        nums = new int[]{8,1,6,3,2,5};
        nums = CycleSort.sortArrayByParityII(nums);

        System.out.println(Arrays.toString(nums));

        for (int idx = 0; idx < nums.length; idx++) {
            var valueAtIdx = nums[idx];
            if (idx % 2 == 0) {
                Assertions.assertEquals(0, nums[idx] % 2);
            } else {
                Assertions.assertEquals(1, nums[idx] % 2);
            }
        }

        nums = new int[]{5,7,3,2,6,4};
        nums = CycleSort.sortArrayByParityII(nums);

        System.out.println(Arrays.toString(nums));

        for (int idx = 0; idx < nums.length; idx++) {
            var valueAtIdx = nums[idx];
            if (idx % 2 == 0) {
                Assertions.assertEquals(0, nums[idx] % 2);
            } else {
                Assertions.assertEquals(1, nums[idx] % 2);
            }
        }

        nums = new int[]{102,473,814,251,604,999};
        nums = CycleSort.sortArrayByParityII(nums);

        System.out.println(Arrays.toString(nums));

        for (int idx = 0; idx < nums.length; idx++) {
            var valueAtIdx = nums[idx];
            if (idx % 2 == 0) {
                Assertions.assertEquals(0, nums[idx] % 2);
            } else {
                Assertions.assertEquals(1, nums[idx] % 2);
            }
        }

        nums = new int[]{0,1,2,3,4,5};
        nums = CycleSort.sortArrayByParityII(nums);

        System.out.println(Arrays.toString(nums));

        for (int idx = 0; idx < nums.length; idx++) {
            var valueAtIdx = nums[idx];
            if (idx % 2 == 0) {
                Assertions.assertEquals(0, nums[idx] % 2);
            } else {
                Assertions.assertEquals(1, nums[idx] % 2);
            }
        }
    }
}
