import time

from src.DS import csort
from src.DS import hsort
from src.DS import msort
from src.DS import qsort
from src.DS import IntFileGenerator


def display(arr, str):
    banner = "--------------------"
    print(banner, str, banner)
    print(arr)


def main():
    # ----------------------------- QuickSort -------------------------
    size: int = 1000
    rang: int = 600
    Qf = IntFileGenerator(size, inputFileName="QsortInput.txt", outFileName="QsortOutput.txt")
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
    Mf = IntFileGenerator(size, rang, "MsortInput.txt", "MsortOutput.txt")
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
    Hf = IntFileGenerator(size, rang, "HsortInput.txt", "HsortOutput.txt")
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
    Cf = IntFileGenerator(size, rang, "CsortInput.txt", "CsortOutput.txt")
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
