
#ifndef BST_H_   
#define BST_H_ 

#include <iostream>
using namespace std;
/* 
 *   BST 
 *             10 
 *          /       \
 *         /         \ 
 *        5           15 
 *      /  \       /      \
 *     2     5    13       22
 *    /             \     /  \
 *  1                14  20  25
 */

class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int val);
  BST &insert(int val);
  bool contains(int val);
  int min();
  int max();
  BST& remove(int val);
  void inorder(ostream &out=cout);
  ~BST();

  private: 
    BST* findMin(BST *node);
    BST* findMax(BST *node);
    void Inorder(BST *node, ostream &out);
};

#endif