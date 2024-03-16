import time

from DS.sorting.counting_sort import csort
from DS.sorting.heap_sort import hsort
from DS.sorting.merge_sort import msort
from DS.sorting.quick_sort import qsort
from DS.util.file_generator import IntFileGenerator

def display(arr, str):
    banner = "--------------------"
    print(banner, str, banner)
    print(arr)


def main():
    # ----------------------------- QuickSort -------------------------
    size: int = 1000
    rang: int = 600
    Qf = IntFileGenerator(size, rang, "data/QsortInput.txt", "data/QsortOutput.txt")
    Qf.generate()
    Qarr = range(1, 50, 3)
    Qf.write(Qarr)
    Qarr = Qf.read()
    count = Qarr[0]
    Qarr = Qarr[1:]
    display(Qarr, "QuickSort: Input Array")
    start = time.time_ns()
    qsort(Qarr)
    end = time.time_ns()
    print("Time Spent in Sorting via Quick Sort(in nanosec):", (end - start))
    Qf.write(Qarr)
    display(Qarr, "QuickSort: Output Array")

    # ----------------------------- MergeSort ------------------------
    size = 1000
    rang = 600
    Mf = IntFileGenerator(size, rang, "data/MsortInput.txt", "data/MsortOutput.txt")
    Mf.generate()
    Marr = Mf.read()
    Marr = Marr[1:]
    display(Marr, "MergeSort: Input Array")
    start = time.time_ns()
    msort(Marr)
    end = time.time_ns()
    print("Time Spent in Sorting via Merge Sort(in nanosec):", (end - start))
    display(Marr, "MergeSort:Output Array")
    Mf.write(Marr)

    # ----------------------------- Heap Sort ------------------------
    size = 1000
    rang = 600
    Hf = IntFileGenerator(size, rang, "data/HsortInput.txt", "data/HsortOutput.txt")
    Hf.generate()
    Harr = Hf.read()
    Harr = Harr[1:]
    display(Harr, "Heap Sort: Input Array")
    start = time.time_ns()
    hsort(Harr)
    end = time.time_ns()
    print("Time Spent in Sorting via Heap Sort(in nanosec):", (end - start))
    display(Harr, "HeapSort:Output Array")
    Hf.write(Harr)

    # ----------------------------- Counting Sort ------------------------
    size = 20
    rang = 20
    Cf = IntFileGenerator(size, rang, "data/CsortInput.txt", "data/CsortOutput.txt")
    Cf.generate()
    Carr = Cf.read()
    Carr = Carr[1:]
    display(Carr, "Counting Sort: Input Array")
    start = time.time_ns()
    csort(Carr, rang)
    end = time.time_ns()
    print("Time Spent in Sorting via Counting Sort(in nanosec):", (end - start))
    display(Carr, "CountingSort:Output Array")
    Cf.write(Carr)


main()

if __name__ == '___main__;':
    print("Running Main")
