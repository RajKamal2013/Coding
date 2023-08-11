package DS.Sorting;

import java.util.Vector;

public class CSort
{
    static void CountingSort(Integer[] arr, int range) {
        int size = arr.length;
        int[] rank = new int[range];
        int[] aux = new int[size];

        for(int i = 0;i < range; i++) {
            rank[i] = 0;
        }

        for (int i =0;i < size; i++) {
            rank[arr[i]] = rank[arr[i]] + 1;
        }

        for (int i = 1; i < range; i++) {
            rank[i] = rank[i] + rank[i -1];
        }

        for (int i = size - 1; i  >= 0; i--) {
            aux[rank[arr[i]] -1] = arr[i];
            rank[arr[i]] = rank[arr[i]] - 1;
        }

        for (int i = 0;i < size; i++) {
            arr[i] = aux[i];
        }
    }

    public static void Sort(Integer[] arr, int range) {
        if (arr.length == 1) {
            return;
        }
        CountingSort(arr, range);
    }


}
