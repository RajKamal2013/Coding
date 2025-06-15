package DS.Sorting;

import java.util.Vector;

public class HSort
{
    static void swap(Vector<Integer> arr, int x, int y) {
        int temp = arr.get(x);
        arr.set(x, arr.get(y));
        arr.set(y, temp);
    }

    static void MaxHeapify(Vector<Integer> arr, int index, int heapsize)
    {
        int left = 2*index + 1;
        int right = 2*index + 2;

        int largest;

        if ((left < heapsize) && (arr.get(left) > arr.get(index))) {
            largest = left;
        } else {
            largest = index;
        }

        if ((right < heapsize) && (arr.get(right) > arr.get(largest))) {
            largest = right;
        }

        if (largest != index) {
            swap(arr, largest, index);
            MaxHeapify(arr, largest, heapsize);
        }
    }

    static void BuilMaxHeap(Vector<Integer> arr)
    {
        int heapsize = arr.size();
        int i = 0;
        for (i = heapsize/2; i >= 0; i--){
            MaxHeapify(arr, i, heapsize);
        }
    }

    static void HeapSort(Vector<Integer> arr)
    {
        int heapsize = arr.size();
        BuilMaxHeap(arr);
        for (int i = arr.size() - 1; i > 0; i--) {
            swap(arr, i, 0);
            heapsize = heapsize - 1;
            MaxHeapify(arr, 0, heapsize);
        }
    }

    public static void Sort(Vector<Integer> arr) {
        if (arr.size() == 1) {
            return;
        }
        HeapSort(arr);
    }
}
