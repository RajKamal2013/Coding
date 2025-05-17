# About 
This includes Data structures and algorithm code. Aim to includes problem that help in tacking coding problems. Problems solved helps developing attitude that can assit in interview, day to day coding.

Currently I have covered problems in 
1. DP
2. Tree

# Automake 
## Compiling and Building
```
./autogen.sh
cd bld 
../configure
make 
```

## Testing 
Below directories contains binary which can be run 
```
cd bld/src/DP/
cd bld/src/Tree/
```



# CMake 
## Compiling and Building
```
cmake -S . -B build
cmake --build build 
```

## Testing 
```
cd build/src/DP/
cd build/src/Tree/
```


# Bazel

## Compiling and Building
```
bazel build //src/DP:DPMain
bazel build //src/DP:DPMaxSubSequenceSumNonAdjacent
bazel build //src/DP:LevenshteinDistance
```
