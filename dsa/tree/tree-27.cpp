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

// ── Lowest Common Ancestor of a Binary Tree ───────────────────

// T: O(n)  S: O(h)
class Recursion {
private:
  TreeNode *dfs(TreeNode *node, TreeNode *p, TreeNode *q) {
    if (node == nullptr)
      return nullptr;
    if (node == p)
      return p;
    if (node == q)
      return q;
    TreeNode *left = dfs(node->left, p, q);
    TreeNode *right = dfs(node->right, p, q);
    if (left && right)
      return node;
    if (left)
      return left;
    if (right)
      return right;
    return nullptr;
  }

public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    return dfs(root, p, q);
  }
};
