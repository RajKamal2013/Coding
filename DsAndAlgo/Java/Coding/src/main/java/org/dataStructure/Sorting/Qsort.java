package DS.Sorting;

import java.util.Vector;

public class Qsort {
    static void swap(Vector<Integer> arr, int x, int y) {
        int temp = arr.get(x);
        arr.set(x, arr.get(y));
        arr.set(y, temp);
    }

    static int partition(Vector<Integer> arr, int start, int end) {
            int pivot = arr.get(end);
            int j = start - 1;
            int i = start;

            while(i < end) {
                if (arr.get(i) < pivot) {
                    j = j + 1;
                    swap(arr, i, j);
                }
                i = i + 1;
            }
            j = j + 1;
            swap(arr, j, end);
            return j;
    }

     public static void Sort(Vector<Integer> arr) {
        if (arr.size() <= 1) {
            return;
        }
        QuickSort(arr, 0, arr.size() - 1);
    }

    static void QuickSort(Vector<Integer> arr, int start, int end) {
        int pivot;
        if (start < end) {
            pivot = partition(arr, start, end);
            QuickSort(arr, start, pivot -1);
            QuickSort(arr, pivot + 1, end);
        }
    }
}
