/* 
 * Find kth largest value in the BST.  
 */

#include "BST.h"
#include <iostream>
using namespace std;

void KthLargestValueInBst_int(BST *tree, int k, int &lastVisited, int &count) {
     if ((tree == nullptr) || (count >= k)) {
       return;
     }
  
    KthLargestValueInBst_int(tree->right, k, lastVisited, count);
    if (count < k) {
      lastVisited = tree->value;
      count = count + 1;
      KthLargestValueInBst_int(tree->left, k, lastVisited, count);
    }
}
int findKthLargestValueInBst(BST *tree, int k) {
   int lastVisited = -1;
   int count  = 0;
   KthLargestValueInBst_int(tree, k, lastVisited, count);
   return lastVisited;
}


