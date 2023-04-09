#ifndef BinaryTree_H
#define BinaryTree_H

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

class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int val);
  BinaryTree &insertBST(int val);
  BinaryTree &insert(int val);
  //BinaryTree &insert(vector<int> val);
  void inorder(ostream &out=cout);
  void levelOrder(ostream &out=cout);
  BinaryTree *getNode(int value, int occurance);
  bool heightBalancedBinaryTree();
  
private: 
  BinaryTree &insert_int(BinaryTree *node, int val);
  void inorder_int(BinaryTree *node, ostream &out);
  void levelOrder_int(BinaryTree *node, ostream &out=cout);
  BinaryTree *getNode_int(BinaryTree *node, int value, int occurance);
  int heightBalancedBinaryTree_int(BinaryTree *tree, bool &isBalanced);
 // bool contains(int val);
 // int min();
 // int max();
 // BinaryTree& remove(int val);
  
 // ~BinaryTree();

 // private: 
  //  BinaryTree* findMin(BinaryTree *node);
  //  BinaryTree* findMax(BinaryTree *node);
  //  void Inorder(BinaryTree *node, ostream &out);
};

#endif