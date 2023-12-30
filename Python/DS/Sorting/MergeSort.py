def merge(arr, start, mid, end):
    lsize:int = int(mid) - int(start) + 1
    rsize:int = int(end) - int(mid)

    larr = [None] * lsize
    rarr = [None] * rsize

    i = j = 0
    for i in range(lsize):
        larr[i] = arr[start + i]

    for j in range(rsize):
        rarr[j] = arr[mid + 1 + j]

    i = j = 0
    k = start

    while (i < lsize) and (j < rsize):
        if larr[i] < rarr[j] :
            arr[k] = larr[i]
            i = i + 1
        else :
            arr[k] = rarr[j]
            j = j + 1

        k = k + 1

    while i < lsize:
        arr[k] = larr[i]
        k = k + 1
        i = i + 1

    while j < rsize:
        arr[k] = rarr[j]
        k = k + 1
        j = j + 1


def mergesort(arr, start:int, end:int):
    if start < end:
        mid = int(start + (end - start)/2)
        mergesort(arr, start, mid)
        mergesort(arr, mid + 1, end)
        merge(arr, start, mid, end)

def msort(arr):
    if len(arr) <= 1:
        return
    mergesort(arr, 0, len(arr) - 1)

