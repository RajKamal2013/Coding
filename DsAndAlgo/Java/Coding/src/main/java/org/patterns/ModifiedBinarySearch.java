package org.patterns;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class ModifiedBinarySearch {

    public static int singleNonDuplicateUnOptimized(int[] nums) {
        if (nums == null || nums.length == 0) {
            return Integer.MAX_VALUE;
        }

        if (nums.length == 1) {
            return nums[0];
        }

        int left = 0;
        int right = nums.length - 1;
        int mid;
        int target = -1;

        while (left <= right) {
            if (left == right) {
                target = nums[left];
                break;
            }

            mid = (left + right) / 2;
            int lSize, rSize;

            if (nums[mid - 1] != nums[mid]  && nums[mid] != nums[mid + 1]) {
                target = nums[mid];
                break;
            } else if (nums[mid] == nums[mid - 1]) {
                rSize = right - (mid + 1) + 1;
                if (rSize % 2 != 0) {
                    left = mid + 1;
                }
                if (mid - 2 >= 0) {
                    lSize = left - (mid - 2) + 1;
                    if (lSize % 2 != 0) {
                        right = mid - 2;
                    }
                }
            } else { // (nums[mid] == nums[mid + 1])
                rSize = right - (mid + 2) + 1;
                lSize = (mid - 1) - left  + 1;
                if (mid + 2 < nums.length) {
                    if (rSize % 2 != 0) {
                        left = mid + 2;
                    }
                }
                if (lSize % 2 != 0) {
                    right = mid - 1;
                }
            }
        }
        // Replace this placeholder return statement with your code
        return target;
    }

    public static int singleNonDuplicate(int[] nums) {
        int left, right;
        left = 0;
        right = nums.length - 1;

        while (left < right ) {  // we don't need to do left == right as its the answer.
            int mid = left + (right - left)/2;

            // move mid to even size. (Duplicates pairs (0,1), (2, 3), (4,5)
            if (mid % 2 == 1) mid--;

            // move mid twice since size is in pair
            if (nums[mid] == nums[mid+1]) { // (0, 1) (2, 3), (4, 5) till mid satisfy, so move right to see
                left = mid + 2;
            } else { // we need to see from mid to end, as its odd // index is odd, means even number pair broke in left, go left
                right = mid;
            }
        }
        return nums[left];
    }


    /* nums.length > 0 and target can't  be null */
    public static int binarySearch(int[] arr, int target) {
        int left = 0;
        int right = arr.length - 1;

        while (left <= right) {  // == when [1, 3, 7] -> search 7
            int mid = left + (right - left)/2;
            if (arr[mid] == target) {
                return mid;
            }

            if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left; // if number is found then left is the answer ow left is nearest to the target or out of index
    }

    public static List<Integer> findClosestElements(int[] nums, int k, int target) {
        if (nums == null || nums.length == 0) {
            return new ArrayList<>();
        }

        if (nums.length == 1) {
            return new ArrayList<>(Arrays.asList(nums[0]));
        }

        List<Integer> kClosest = new ArrayList<>();
        if (nums.length == k) {
            for (int num:nums) {
                kClosest.add(num);
            }
            return kClosest;
        }

        if (target <= nums[0]) {
            for (int i = 0; i < k; i++) {
                kClosest.add(nums[i]);
            }
            return kClosest;
        }

        if (nums[nums.length - 1] <= target) {
            for (int i = nums.length - k; i < nums.length; i++){
                kClosest.add(nums[i]);
            }
            return kClosest;
        }

        int pos = binarySearch(nums, target);
        int leftIdx = pos - 1;
        int rightIdx = pos;

        while ((rightIdx - leftIdx - 1) < k) {
             if (leftIdx == -1) {
                 rightIdx++;
                 continue;
             }

             if (rightIdx == nums.length) {
                 leftIdx--;
                 continue;
             }

             if (Math.abs(nums[leftIdx] - target) <= Math.abs(nums[rightIdx] - target)) {
                 leftIdx--;
             } else {
                 rightIdx++;
             }
        }

        System.out.printf("\nLeftIDx %d-%d RightIdx %d-%d \n", leftIdx, nums[leftIdx], rightIdx, nums[rightIdx]);

        for (int i = leftIdx + 1; i < rightIdx; i++) {
            kClosest.add(nums[i]);
        }

        /*
        while (kClosest.size() < k) {
            if (leftIdx < 0) {
                kClosest.add(nums[rightIdx++]);
                continue;
            }
            if (rightIdx >= nums.length) {
                kClosest.addFirst(nums[leftIdx--]);
                continue;
            }
            if (Math.abs(nums[leftIdx] - target) <= Math.abs(nums[rightIdx] - target)) {
                kClosest.addFirst(nums[leftIdx--]);
            } else {
                kClosest.add(nums[rightIdx++]);
            }
        }

         */

        // Replace this placeholder return statement with your code
        return kClosest;
    }

    /* nums.length > 0 and target can't  be null */
    public static int binarySearchWithInRange(int[] arr, int left,
                                              int right , int target) {
        while (left <= right) {  // == when [1, 3, 7] -> search 7
            int mid = left + (right - left)/2;
            if (arr[mid] == target) {
                return mid;
            }

            if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }

    public static int binarySearchRotated(int[] nums, int target) {
        if (nums == null || nums.length == 0) {
            return -1;
        }

        if (nums.length == 1) {
            return (nums[0] == target) ? 0: -1;
        }

        int left = 0;
        int right = nums.length - 1;

        if (nums[left] < nums[right]) {
            int searchedIdx = binarySearchWithInRange(nums, 0, nums.length - 1, target);
            return (nums[searchedIdx] == target) ? searchedIdx: -1;
        }

        int mid = left + (right - left)/2;
        // same elements in array
        if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
            return (nums[mid] == target) ? left: -1;
        }

        int pivot = -1;
        // Find the smallest number in the array (rotated index)
        while (left < right) {
            mid = left + (right - left)/2;
            if (nums[mid] > nums[right]) {
                left =  mid + 1;
            } else if (nums[mid] < nums[right]){
                right = mid;
            } else { //(nums[left] < nums[mid]) {
                right = right - 1;
            }
        }

        int searchInLeft;
        pivot = left;
        if (pivot > 0) {
            searchInLeft = binarySearchWithInRange(nums, 0, pivot - 1, target);
            if (nums[searchInLeft] == target) {
                return searchInLeft;
            }
        }

        int searchInRight = binarySearchWithInRange(nums, pivot, nums.length -1, target);
        if (searchInRight == nums.length) {
            return -1;
        }
        if (nums[searchInRight] == target) {
            return searchInRight;
        }

        return -1;
    }


    public static int binarySearchWithInRange1(int[] arr, int left, int right, int target) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target) {
                return mid;
            }

            if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }





}
