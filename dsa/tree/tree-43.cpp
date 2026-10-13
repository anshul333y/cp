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

// ── Insert into a Binary Search Tree ──────────────────────────

// T: O(h)  S: O(1)
class Iterative {
public:
  TreeNode *insertIntoBST(TreeNode *root, int val) {
    if (root == nullptr)
      return new TreeNode(val);
    TreeNode *node = root;
    while (node) {
      if (node->val > val) {
        if (node->left == nullptr) {
          node->left = new TreeNode(val);
          break;
        }
        node = node->left;
      } else {
        if (node->right == nullptr) {
          node->right = new TreeNode(val);
          break;
        }
        node = node->right;
      }
    }
    return root;
  }
};
