#! /bin/bash


rm -rf bld 
rm -rf build
rm -rf bazel-out
rm -rf bazel-CPP
rm -rf bazel-bin
rm -rf bazel-testlogs
rm -rf aclocal.m4
rm -rf autom4te.cache
rm -rf compile
rm -rf configure
rm -rf install-sh
rm -rf depcomp
rm -rf missing
rm -rf Makefile.in

find . -name "*.in" -type f
find . -name "*.in" -type f -delete

find . -name "*.bak" -type f
find . -name "*.bak" -type f -delete
