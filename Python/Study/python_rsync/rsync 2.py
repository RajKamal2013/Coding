import os
import sys
import filecmp
import shutil
from stat import *


class Directory:
    def __init__(self, path, name=''):
        self.root_path = os.path.abspath(path)
        self.name = name
        self.fileList = os.listdir(self.root_path)

class My_Resync:
    def __init__(self, name='', dir1='', dir2=''):
        self.name = name
        self.dir1=dir1
        self.dir2=dir2
        self.file_copy_count = 0
        self.dir_copy_count = 0

    def compare_dirs(self):
        self._compare_dirs(self.dir1.root_path, self.dir2.root_path)

    def _compare_dirs(self, left, right):
        dcmp = filecmp.dircmp(left, right)
        if dcmp.common_dirs:
            for d in dcmp.common_dirs:
                self._compare_dirs(os.path.join(left, d), os.path.join(right, d))

        if dcmp.left_only:
            self.copy(dcmp.left_only, left, right)

        if dcmp.right_only:
            self.copy(dcmp.right_only, right, left)

        left_newer = []
        right_newer = []

        if dcmp.diff_files:
            for d in dcmp.diff_files:
                l_modified = os.stat(os.path.join(left, d)).st_mtime
                r_modified = os.stat(os.path.join(right, d)).st_mtime

                if (l_modified > r_modified):
                    left_newer.append(d)
                else:
                    right_newer.append(d)

                self.copy(left_newer, left, right)
                self.copy(right_newer, right, left)


    def copy(self, fileList, src, dest):
        for f in fileList:
            src_path = os.path.join(src, os.path.basename(f))

            if (os.path.isdir(src_path)):
                shutil.copytree(src_path, os.path.join(dest, os.path.basename(f)))
                self.dir_copy_count = self.dir_copy_count + 1
            else:
                shutil.copy2(src_path, dest)




if __name__ == "__main__":
    src_dir = Directory("/Users/rajkamal/Documents/work/Python/Python_Codes/LeetCode", "dir1")
    dest_dir = Directory("/Users/rajkamal/Documents/work/Python/Python_Codes/LeetCode_Temp", "dir2")
    my_resync = My_Resync("mysync", src_dir, dest_dir)
    my_resync.compare_dirs()



