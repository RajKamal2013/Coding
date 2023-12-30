def partition(arr, start:int, end:int):
    pivot = arr[end]
    i:int = int(start)
    j:int = int(i - 1)

    while (i < end):
        if (arr[i] < pivot):
            j = j + 1
            arr[i], arr[j] = arr[j], arr[i]

        i = i + 1

    j = j + 1
    arr[j], arr[end] = arr[end], arr[j]
    return int(j)


def quickSort(arr, start:int, end:int):
    if (start < end):
        pivot = int(partition(arr, start, end))
        quickSort(arr, start, pivot - 1)
        quickSort(arr, pivot + 1, end)

def qsort(arr):
    quickSort(arr, 0, len(arr) - 1)


