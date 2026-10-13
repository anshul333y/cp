#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

// ── Title ────────────────────────────────────────────────────

// T: O(n)  S: O(h)
class Recursion {
  // to create a unique binary tree you need inorder and one of preorder or
  // postorder with it
};
