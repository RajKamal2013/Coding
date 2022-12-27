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

add_executable(KthLargestValue
               Tree/BST.h Tree/BST.cpp
               Tree/KthLargestValueInBST.h
               Tree/KthLargestValueInBSTTest.cpp
            )
add_executable(ReconstructBST
                Tree/BST.h Tree/BST.cpp
                Tree/ReconstructBST.h 
                Tree/ReconstructBSTTest.cpp
                )     
                
add_executable(SameBST
                Tree/BST.h Tree/BST.cpp
                Tree/SameBSTs.h 
                Tree/SameBSTsTest.cpp
                )  
add_executable(BranchSum
                Tree/BST.h Tree/BST.cpp
                Tree/BranchSum.h 
                Tree/BranchSumTest.cpp
              )
add_executable(NodeDepth
               Tree/BST.h Tree/BST.cpp
               Tree/NodeDepth.h 
               Tree/NodeDepthTest.cpp
              )
add_executable(InvertBinaryTree
              Tree/BinaryTree.h Tree/BinaryTree.cpp 
              Tree/InvertBinaryTree.h 
              Tree/InvertBinaryTreeTest.cpp 
              )
add_executable(BinaryTreeDiamter
              Tree/BinaryTree.h Tree/BinaryTree.cpp 
              Tree/Diameter.h 
              Tree/DiameterTest.cpp 
              )
     

target_compile_features(srcMain PUBLIC cxx_std_11)

