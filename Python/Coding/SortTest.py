import time

from Coding.Sorting.CountingSort import CSort
from Coding.Sorting.HeapSort import hSort
from Coding.Sorting.MergeSort import msort
from Coding.Sorting.QuickSort import qsort
from Coding.Util import FileGenerator


def display(arr, str):
    banner = "--------------------"
    print(banner, str, banner)
    print(arr)


def main():

    # ----------------------------- QuickSort -------------------------
    size:int = 1000
    rang:int = 600
    Qf = FileGenerator.IntFileGenerator(size, rang, "QsortInput.txt", "QsortOutput.txt")
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
    print("Time Spent in Sorting via Quick Sort(in nanosec):", (end-start))
    Qf.write(Qarr)
    display(Qarr, "QuickSort: Output Array")

    # ----------------------------- MergeSort ------------------------
    size = 1000
    rang = 600
    Mf = FileGenerator.IntFileGenerator(size, rang, "MsortInput.txt", "MsortOutput.txt")
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
    Hf = FileGenerator.IntFileGenerator(size, rang, "HsortInput.txt", "HsortOutput.txt")
    Hf.generate()
    Harr = Hf.read()
    Harr = Harr[1:]
    display(Harr, "Heap Sort: Input Array")
    start = time.time_ns()
    hSort(Harr)
    end = time.time_ns()
    print("Time Spent in Sorting via Heap Sort(in nanosec):", (end - start))
    display(Harr, "HeapSort:Output Array")
    Hf.write(Harr)

    # ----------------------------- Counting Sort ------------------------
    size =  20
    rang = 20
    Cf = FileGenerator.IntFileGenerator(size, rang, "CsortInput.txt", "CsortOutput.txt")
    Cf.generate()
    Carr = Cf.read()
    Carr = Carr[1:]
    display(Carr, "Counting Sort: Input Array")
    start = time.time_ns()
    CSort(Carr, rang)
    end = time.time_ns()
    print("Time Spent in Sorting via Counting Sort(in nanosec):", (end - start))
    display(Carr, "CountingSort:Output Array")
    Cf.write(Carr)


main()

if __name__ == '___main__;':
    print("Running Main")