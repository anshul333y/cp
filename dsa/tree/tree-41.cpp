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

// ── Ceil in a Binary Search Tree ───────────────────────────────

// T: O(h)  S: O(1)
class Iterative {
public:
  int findCeil(Node *root, int x) {
    int ceil = -1;
    Node *node = root;
    while (node) {
      if (node->data == x) {
        ceil = node->data;
        break;
      } else if (node->data > x) {
        ceil = node->data;
        node = node->left;
      } else {
        node = node->right;
      }
    }
    return ceil;
  }
};
