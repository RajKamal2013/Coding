add_executable (srcMain main.cpp)
add_executable(treeTest
               Tree/debug.h
               Tree/main.cpp
               Tree/BSTTest.h 
               Tree/BST.h Tree/BST.cpp
               )
add_executable(BST
               Tree/main.cpp
               Tree/BSTTest.h
               Tree/BST.h Tree/BST.cpp 
              )              
add_executable(FindClosestValue
               Tree/BST.h Tree/BST.cpp 
               Tree/FindClosestValue.h
               Tree/FindClosestValueTest.cpp
              )                   
add_executable(ValidateBST 
              Tree/BST.h Tree/BST.cpp 
              Tree/ValidateBST.h
              Tree/ValidateBSTTest.cpp
              )

add_executable(MinHeightBST
              Tree/MinHeightBST.h
              Tree/MinHeightBSTTest.cpp
              )

target_compile_features(srcMain PUBLIC cxx_std_11)

