add_executable (TreeMain 
                main.cpp)

add_executable(treeTest
               debug.h
               main.cpp
               BSTTest.h 
               BST.h BST.cpp
               )
target_compile_features(treeTest PUBLIC cxx_std_11)

add_executable(BST
               main.cpp
               BSTTest.h
               BST.h BST.cpp 
              ) 

add_executable(BinaryTree
              BinaryTree.h BinaryTree.cpp
              BinaryTreeTest.cpp 
             )

add_executable(FindClosestValue
               BST.h BST.cpp 
               FindClosestValue.h
               FindClosestValueTest.cpp
              )

add_executable(ValidateBST 
              BST.h BST.cpp 
              ValidateBST.h
              ValidateBSTTest.cpp
              )

add_executable(MinHeightBST
              MinHeightBST.h
              MinHeightBSTTest.cpp
              )

add_executable(KthLargestValue
               BST.h BST.cpp
               KthLargestValueInBST.h
               KthLargestValueInBSTTest.cpp
            )

add_executable(ReconstructBST
                BST.h BST.cpp
                ReconstructBST.h 
                ReconstructBSTTest.cpp
                )     
                
add_executable(SameBST
                BST.h BST.cpp
                SameBSTs.h 
                SameBSTsTest.cpp
                )

add_executable(BranchSum
                BST.h BST.cpp
                BranchSum.h 
                BranchSumTest.cpp
              )

add_executable(NodeDepth
               BST.h BST.cpp
               NodeDepth.h 
               NodeDepthTest.cpp
              )

add_executable(InvertBinaryTree
              BinaryTree.h BinaryTree.cpp 
              InvertBinaryTree.h 
              InvertBinaryTreeTest.cpp 
              )

add_executable(BinaryTreeDiamter
              BinaryTree.h BinaryTree.cpp 
              Diameter.h 
              DiameterTest.cpp 
              )

add_executable(Successor
              BinaryTree.h BinaryTree.cpp 
              FindSuccessor.h 
              FindSuccessorTest.cpp 
              )

add_executable(MergeBinaryTree
              BinaryTree.h BinaryTree.cpp 
              MergeBinaryTree.h 
              MergeBinaryTreeTest.cpp 
              )

add_executable(SymmetricalBinaryTree
              BinaryTree.h BinaryTree.cpp 
              SymmetricalTree.h 
              SymmetricalTreeTest.cpp
              )         
  
