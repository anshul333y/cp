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

// ── Floor in a Binary Search Tree ──────────────────────────────

// T: O(h)  S: O(1)
class Iterative {
public:
  int findMaxFork(Node *root, int k) {
    int ans = -1;
    Node *node = root;
    while (node) {
      if (node->data == k) {
        ans = node->data;
        break;
      } else if (node->data < k) {
        ans = node->data;
        node = node->right;
      } else {
        node = node->left;
      }
    }
    return ans;
  }
};
