add_executable (srcMain main.cpp)
add_executable(treeTest Tree/main.cpp Tree/testBST.h Tree/BST.h Tree/BST.cpp )

target_compile_features(srcMain PUBLIC cxx_std_11)

