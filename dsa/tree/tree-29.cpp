#include <bits/stdc++.h>
using namespace std;

class Node {
public:
  int data;
  Node *left, *right;
  Node(int val) {
    data = val;
    left = right = nullptr;
  }
};

template <typename T> class BinaryTreeNode {
public:
  T data;
  BinaryTreeNode<T> *left;
  BinaryTreeNode<T> *right;
  BinaryTreeNode(T data) {
    this->data = data;
    left = NULL;
    right = NULL;
  }
};

// ── Children Sum Property ─────────────────────────────────────

// T: O(n)  S: O(h)
class Recursion {
public:
  bool isSumProperty(Node *root) {
    if (root == nullptr)
      return true;
    if (root->left && root->right) {
      if (root->left->data + root->right->data != root->data)
        return false;
    } else if (root->left) {
      if (root->left->data != root->data)
        return false;
    } else if (root->right) {
      if (root->right->data != root->data)
        return false;
    }
    if (isSumProperty(root->left) == false)
      return false;
    if (isSumProperty(root->right) == false)
      return false;
    return true;
  }
};

// ── Change a Binary Tree ───────────────────────────────────────

// T: O(n)  S: O(h)
class Recursion2 {
public:
  void dfs(BinaryTreeNode<int> *root) {
    if (root == nullptr)
      return;
    int left = 0, right = 0;
    if (root->left)
      left = root->left->data;
    if (root->right)
      right = root->right->data;
    if (left + right >= root->data) {
      root->data = left + right;
    } else if (left && right)
      root->left->data += root->data - (left + right);
    else if (left)
      root->left->data = root->data;
    else if (right)
      root->right->data = root->data;
    dfs(root->left);
    dfs(root->right);
    left = 0, right = 0;
    if (root->left)
      left = root->left->data;
    if (root->right)
      right = root->right->data;
    if (left || right)
      root->data = left + right;
  }
  void changeTree(BinaryTreeNode<int> *root) { dfs(root); }
};
