"""
This Code does not work Properly. Need to fix things here...
"""


def counting_sort(arr, rang: int):
    aux = [0] * len(arr)
    rankArr = [0] * (rang + 1)
    print("start:", rankArr)
    idx: int = 0
    while idx < len(arr) :
        rankArr[arr[idx]] = rankArr[arr[idx]] + 1
        idx = idx + 1
    print("Indexed Rank:", rankArr)
    idx = 1
    while idx < rang:
        rankArr[idx] = rankArr[idx] + rankArr[idx - 1]
        idx = idx + 1
    print("Ranked Rank:", rankArr)
    idx = len(arr) - 1
    while idx >= 0:
        aux[rankArr[arr[idx]] - 1] = arr[idx]
        idx = idx - 1

    print("aux:", aux)
    idx = 0
    while idx < len(arr):
        arr[idx] = aux[idx]
        idx = idx + 1


def csort(arr, rang: int):
    if len(arr) <= 1:
        return
    counting_sort(arr, rang)
