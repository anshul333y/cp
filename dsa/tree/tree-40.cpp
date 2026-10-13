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

// ── Search in a Binary Search Tree ─────────────────────────────

// T: O(h)  S: O(1)
class Iterative {
public:
  TreeNode *searchBST(TreeNode *root, int val) {
    TreeNode *node = root;
    while (node != nullptr && node->val != val) {
      node = node->val > val ? node->left : node->right;
    }
    return node;
  }
};
