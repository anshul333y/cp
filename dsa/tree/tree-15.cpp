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

// ── Balanced Binary Tree ──────────────────────────────────────

// T: O(n)  S: O(h)
class Recursion {
private:
  int dfs(TreeNode *node, bool &ans) {
    if (node == nullptr)
      return 0;
    int left = dfs(node->left, ans);
    int right = dfs(node->right, ans);
    if (abs(left - right) > 1)
      ans = false;
    return 1 + max(left, right);
  }

public:
  bool isBalanced(TreeNode *root) {
    bool ans = true;
    dfs(root, ans);
    return ans;
  }
};
