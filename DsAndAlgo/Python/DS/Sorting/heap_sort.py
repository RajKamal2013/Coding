def max_heapify(arr, index: int, heapSize: int):
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
        max_heapify(arr, largest, heapSize)


def build_maxheap(arr):
    heapSize = len(arr)
    i = len(arr) / 2

    while i >= 0:
        max_heapify(arr, i, heapSize)
        i = i - 1


def heap_sort(arr):
    heapSize = len(arr)
    i = len(arr) - 1

    while i > 0:
        arr[i], arr[0] = arr[0], arr[i]
        heapSize = heapSize - 1
        max_heapify(arr, 0, heapSize)
        i = i - 1


def hsort(arr):
    if len(arr) == 1:
        return

    heap_sort(arr)
