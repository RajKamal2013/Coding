add_executable (srcMain main.cpp)
add_executable(treeTest
               Tree/debug.h
               Tree/main.cpp
               Tree/testBST.h Tree/BST.h Tree/BST.cpp 
               Tree/FindClosestValue.h
               Teee/validateBST.h
               )

target_compile_features(srcMain PUBLIC cxx_std_11)

