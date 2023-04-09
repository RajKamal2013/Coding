include_directories(../../headers/)

add_executable(TreeMain 
                ../main.cpp
               )

add_executable(treeTest
              ../main.cpp
               BST.cpp
               )

add_executable(BST
              ../main.cpp
               BST.cpp 
              ) 

add_executable(BinaryTree
              BinaryTree.cpp
              BinaryTreeTest.cpp 
              ../main.cpp
             )

add_executable(FindClosestValue
               BST.cpp 
               FindClosestValueTest.cpp
               ../main.cpp
              )

add_executable(ValidateBST 
               BST.cpp 
               ValidateBSTTest.cpp
               ../main.cpp
              )

add_executable(MinHeightBST
              MinHeightBSTTest.cpp
              ../main.cpp
              )

add_executable(KthLargestValue
               BST.cpp
               KthLargestValueInBSTTest.cpp
               ../main.cpp
            )

add_executable(ReconstructBST
               BST.cpp
              ReconstructBSTTest.cpp
              ../main.cpp
                )     
                
add_executable(SameBST
                 BST.cpp
                SameBSTsTest.cpp
                ../main.cpp
                )

add_executable(BranchSum
                BST.cpp
                BranchSumTest.cpp
                ../main.cpp
              )

add_executable(NodeDepth
               BST.cpp 
               NodeDepthTest.cpp
               ../main.cpp
              )

add_executable(InvertBinaryTree
              BinaryTree.cpp 
              InvertBinaryTreeTest.cpp 
              ../main.cpp
              )

add_executable(BinaryTreeDiamter
               BinaryTree.cpp 
              DiameterTest.cpp 
              ../main.cpp
              )

add_executable(Successor
               BinaryTree.cpp  
              FindSuccessorTest.cpp 
              ../main.cpp
              )

add_executable(MergeBinaryTree
              BinaryTree.cpp 
              MergeBinaryTreeTest.cpp 
              ../main.cpp
              )

add_executable(SymmetricalBinaryTree
               BinaryTree.cpp 
              SymmetricalTreeTest.cpp
              ../main.cpp
              )         
  
