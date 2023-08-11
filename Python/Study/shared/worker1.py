#! /bin/python

import mmap
import os
import time


def main():
    f = open("temp.txt", "rb")
    buf = mmap.mmap(f.fileno(), 0, mmap.MAP_SHARED, mmap.PROT_READ)
    buf.seek(0)
    i = 0
    while i < 100:
        localtime = time.localtime()
        result = time.strftime("%I:%M:%S %p", localtime)
        print(result)
        buf.write(bytes(result))
        time.sleep(10);
        i = i + 1


if __name__ == '__main__' :
    main()

