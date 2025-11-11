package org.patterns;

import java.util.*;

public class KWayMerge {
    static class Pair {
        int sum;
        int list1Idx;
        int list2Idx;

        public Pair(int sum, int list1Idx, int list2Idx) {
            this.sum = sum;
            this.list1Idx = list1Idx;
            this.list2Idx = list2Idx;
        }
    }

    public static List<List<Integer>> kSmallestPairs(int[] list1, int[] list2, int target) {
        if (list1 == null
                || list2 == null
                || list1.length == 0
                || list2.length == 0
                || target == 0) {
            return new ArrayList<>();
        }

        PriorityQueue<Pair> minHeap = new PriorityQueue<>((a, b) -> a.sum - b.sum);
        for (int i = 0; i < Integer.min(list1.length, target); i++) {
            minHeap.offer(new Pair(list1[i] + list2[0], i, 0));
        }

        int count = 0;
        List<List<Integer>> minSumPairs = new ArrayList<>();
        int nextIdx;
        while(!minHeap.isEmpty() && count < target) {
                Pair minSum = minHeap.poll();
                minSumPairs.add(Arrays.asList(list1[minSum.list1Idx], list2[minSum.list2Idx]));
                count = count + 1;
                nextIdx = minSum.list2Idx  + 1;
                if (nextIdx < list2.length) {
                    minHeap.offer(new Pair(list1[minSum.list1Idx] + list2[nextIdx],
                            minSum.list1Idx, nextIdx));

                }
        }
        return minSumPairs;
    }


    public static class MatrixEntry {
        int rowIdx;
        int colIdx;
        int value;

        public MatrixEntry(int rowIdx, int colIdx, int value) {
            this.rowIdx = rowIdx;
            this.colIdx = colIdx;
            this.value = value;
        }
    }
    public static int kthSmallestElementInMatrix(int[][] matrix, int k) {
        if (matrix == null || matrix.length == 0 || k <= 0) {
            return -1;
        }

        PriorityQueue<MatrixEntry> minHeap = new PriorityQueue<>((a, b) ->
                Integer.compare(a.value, b.value));

        int rowLength = matrix.length;
        for (int i = 0; i < rowLength; i++) {
            minHeap.offer(new MatrixEntry(i, 0, matrix[i][0]));
        }

        int count = 0;
        int result = -1;
        while (!minHeap.isEmpty() && count < k){
            MatrixEntry minElement = minHeap.poll();
            count = count + 1;
            int rowIdx = minElement.rowIdx;
            int nextColIdx = minElement.colIdx + 1;
            if (nextColIdx < matrix[rowIdx].length) {
                minHeap.offer(new MatrixEntry(rowIdx, nextColIdx, matrix[rowIdx][nextColIdx]));
            }
            if (count == k) {
                result = minElement.value;
            }
        }
        return result;
    }

    public static List<Integer> printMatrixElementsInSortedOrder(int[][] matrix) {
        if (matrix == null || matrix.length == 0 ) {
            return null;
        }

        PriorityQueue<MatrixEntry> minHeap = new PriorityQueue<>((a, b) ->
                Integer.compare(a.value, b.value));

        List<Integer> sortedMatrixElement = new ArrayList<>();
        int rowLength = matrix.length;
        for (int i = 0; i < rowLength; i++) {
            minHeap.offer(new MatrixEntry(i, 0, matrix[i][0]));
        }

        int count = 0;
        int result = -1;
        while (!minHeap.isEmpty()){
            MatrixEntry minElement = minHeap.poll();
            count = count + 1;
            int rowIdx = minElement.rowIdx;
            int nextColIdx = minElement.colIdx + 1;
            if (nextColIdx < matrix[rowIdx].length) {
                minHeap.offer(new MatrixEntry(rowIdx, nextColIdx, matrix[rowIdx][nextColIdx]));
            }
            sortedMatrixElement.add(minElement.value);
            System.out.printf("[%d] [%d]: %d\n", minElement.rowIdx, minElement.colIdx, minElement.value);
        }
        return sortedMatrixElement;
    }

    public static class HeapElement {
        int value;
        int idx;
        int list;

        public HeapElement(int value, int idx, int list) {
            this.value = value;
            this.idx = idx;
            this.list = list;
        }
    }
    public static int kSmallestNumberInLists(List<List<Integer>> lists, int k) {
        if (lists == null || lists.isEmpty()) {
            return 0;
        }

        PriorityQueue<HeapElement> minHeap = new PriorityQueue<>((a, b) -> Integer.compare(a.value, b.value));
        for (int i = 0; i < lists.size(); i++) {
            if (!lists.get(i).isEmpty()) {
                minHeap.offer(new HeapElement(lists.get(i).getFirst(), 0, i));
            }
        }

        int count = 0;
        int kthMinElement = -1;

        while (!minHeap.isEmpty() && count < k) {
            HeapElement minElement = minHeap.poll();
            int list = minElement.list;
            int nextIdx = minElement.idx;
            kthMinElement = minElement.value;

            if (nextIdx < lists.get(list).size()) {
                minHeap.offer(new HeapElement(lists.get(list).get(nextIdx), nextIdx, list));
            }
            count = count + 1;
        }
        return kthMinElement;
    }

}
