#include <iostream>
#include <vector>

const int t = 2; // minimum degree of B+ tree

struct Node {
  std::vector<int> keys;
  std::vector<Node*> children;
  bool leaf;

  Node() {
    leaf = true;
  }
};

class BPlusTree {
 public:
  BPlusTree() {
    root = new Node();
  }

  void insert(int key) {
    Node* r = root;
    if (r->keys.size() == 2 * t - 1) {
      Node* s = new Node();
      root = s;
      s->leaf = false;
      s->children.push_back(r);
      splitChild(s, 0);
      insertNonFull(s, key);
    } else {
      insertNonFull(r, key);
    }
  }

  void splitChild(Node* parent, int i) {
    Node* child = parent->children[i];
    Node* newChild = new Node();
    newChild->leaf = child->leaf;
    for (int j = 0; j < t - 1; j++) {
      newChild->keys.push_back(child->keys[j + t]);
    }
    if (!child->leaf) {
      for (int j = 0; j < t; j++) {
        newChild->children.push_back(child->children[j + t]);
      }
    }
    for (int j = parent->keys.size() - 1; j >= i; j--) {
      parent->children[j + 1] = parent->children[j];
    }
    parent->children[i + 1] = newChild;
    for (int j = parent->keys.size() - 1; j >= i; j--) {
      parent->keys[j + 1] = parent->keys[j];
    }
    parent->keys[i] = child->keys[t - 1];
    for (int j = t - 1; j < 2 * t - 1; j++) {
      child->keys.pop_back();
    }
    for (int j = t; j < 2 * t; j++) {
      child->children.pop_back();
    }
  }

  void insertNonFull(Node* node, int key) {
    int i = node->keys.size() - 1;
    if (node->leaf) {
      while (i >= 0 && node->keys[i] > key) {
        node->keys[i + 1] = node->keys[i];
        i--;
      }
      node->keys.insert(node->keys.begin() + i + 1, key);
    } else {
      while (i >= 0 && node->keys[i] > key) {
        i--;
      }
      i++;
      if (node->children[i]->keys.size() == 2 * t - 1) {
        splitChild(node, i);
        if (node->keys[i] < key) {
          i++;
        }
      }
      insertNonFull(node->children[i], key);
