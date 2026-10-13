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

// ── Binary Tree Maximum Path Sum ──────────────────────────────

// T: O(n)  S: O(h)
class Recursion {
private:
  int dfs(TreeNode *node, int &ans) {
    if (node == nullptr)
      return 0;
    int left = max(0, dfs(node->left, ans));
    int right = max(0, dfs(node->right, ans));
    int pathSum = node->val + max(left, right);
    ans = max({ans, pathSum, node->val + left + right});
    return pathSum;
  }

public:
  int maxPathSum(TreeNode *root) {
    int ans = INT_MIN;
    dfs(root, ans);
    return ans;
  }
};
