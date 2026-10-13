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

// ── Maximum Depth of Binary Tree ──────────────────────────────

// T: O(n)  S: O(h)
class Recursion {
private:
  void dfs(TreeNode *node, int level, int &ans) {
    if (node == nullptr)
      return;
    ans = max(ans, level);
    dfs(node->left, level + 1, ans);
    dfs(node->right, level + 1, ans);
  }

public:
  int maxDepth(TreeNode *root) {
    int ans = 0;
    dfs(root, 1, ans);
    return ans;
  }
};
