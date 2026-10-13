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

// ── Validate Binary Search Tree ────────────────────────────────

// T: O(n)  S: O(h)
class Recursion {
private:
  bool rec(TreeNode *node, long long low, long long high) {
    if (node == nullptr)
      return true;
    if (node->val <= low || node->val >= high)
      return false;
    bool left = rec(node->left, low, node->val);
    bool right = rec(node->right, node->val, high);
    return left && right;
  }

public:
  bool isValidBST(TreeNode *root) { return rec(root, LLONG_MIN, LLONG_MAX); }
};
