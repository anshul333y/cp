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

// ── Lowest Common Ancestor of a BST ────────────────────────────

// T: O(h)  S: O(h)
class Recursion {
private:
  TreeNode *rec(TreeNode *node, TreeNode *p, TreeNode *q) {
    if (node == nullptr)
      return nullptr;
    if (node->val > p->val && node->val > q->val)
      return rec(node->left, p, q);
    else if (node->val < p->val && node->val < q->val)
      return rec(node->right, p, q);
    else
      return node;
  }

public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    return rec(root, p, q);
  }
};
