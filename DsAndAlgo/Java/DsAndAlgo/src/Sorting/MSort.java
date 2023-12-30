package DS.Sorting;

import java.util.Vector;

public class MSort
{
    static void Merge(Vector<Integer>arr, int start, int mid, int end) {
         int lsize = mid - start + 1;
         int rsize = end - mid;
         int i, j, k;

         Vector<Integer> larr = new Vector<Integer>(lsize);
         Vector<Integer> rarr = new Vector<Integer>(rsize);

         for (i = 0; i < lsize; i++) {
             larr.add(i, arr.get(start + i));
         }

         for (j = 0; j < rsize; j++) {
             rarr.add(j, arr.get(mid+ 1 + j));
         }

         i = j = 0;
         k = start;

         while ((i < lsize) && (j < rsize)) {
             if (larr.get(i) < rarr.get(j)) {
                 arr.set(k, larr.get(i));
                 i = i + 1;
             } else {
                 arr.set(k, rarr.get(j));
                 j = j + 1;
             }
             k = k + 1;
         }

         while (i < lsize) {
             arr.set(k, larr.get(i));
             k = k + 1;
             i = i + 1;
         }

         while (j < rsize) {
             arr.set(k, rarr.get(j));
             j = j + 1;
             k = k + 1;
         }
    }

    static void MergeSort(Vector<Integer>arr, int start, int end) {
        if (start < end) {
            int mid = start + (end - start) /2;
            MergeSort(arr, start, mid);
            MergeSort(arr, mid + 1, end);
            Merge(arr, start, mid, end);
        }

    }

    static void Sort(Vector<Integer> arr) {
        if (arr.size() == 1) {
            return;
        }
        MergeSort(arr, 0, arr.size() - 1);
    }


}
