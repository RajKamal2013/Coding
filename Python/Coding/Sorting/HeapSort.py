def MaxHeapify(arr, index:int, heapSize:int):
    left = int(2 * index + 1)
    right = int(2 * index + 2)


    if (left < heapSize) and (arr[left] > arr[index]):
        largest = left
    else:
        largest = index

    if (right < heapSize) and (arr[right] > arr[largest]):
        largest = right

    if (largest != index):
        arr[largest], arr[index] = arr[index], arr[largest]
        MaxHeapify(arr, largest, heapSize)


def BuildMaxHeap(arr):
    heapSize = len(arr)
    i = len(arr)/2

    while i >= 0:
        MaxHeapify(arr, i, heapSize)
        i = i - 1

def HeapSort(arr):
    heapSize = len(arr)
    i = len(arr) - 1

    while i > 0 :
        arr[i], arr[0] = arr[0], arr[i]
        heapSize = heapSize - 1
        MaxHeapify(arr, 0, heapSize)
        i = i - 1

def hSort(arr):
    if len(arr) == 1:
        return

    HeapSort(arr)



