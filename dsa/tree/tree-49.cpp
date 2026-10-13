#include <bits/stdc++.h>
using namespace std;

class Node {
public:
  int data;
  Node *left;
  Node *right;
  Node(int val) {
    data = val;
    left = right = nullptr;
  }
};

// ── Inorder Successor in a BST ─────────────────────────────────

// T: O(h)  S: O(1)
class Iterative {
public:
  int inOrderSuccessor(Node *root, Node *k) {
    int ans = -1;
    while (root != nullptr) {
      if (root->data <= k->data) {
        root = root->right;
      } else {
        ans = root->data;
        root = root->left;
      }
    }
    return ans;
  }
};
