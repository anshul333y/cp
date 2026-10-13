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

// ── Count Complete Tree Nodes ──────────────────────────────────

// T: O(n)  S: O(h)
class Recursion {
private:
  int dfs(TreeNode *node) {
    if (node == nullptr)
      return 0;
    return 1 + dfs(node->left) + dfs(node->right);
  }

public:
  int countNodes(TreeNode *root) { return dfs(root); }
};

// T: O(log^2 n)  S: O(log n)
class BinarySearch {
private:
  int heightLeft(TreeNode *node) {
    int ans = 0;
    while (node) {
      ans++;
      node = node->left;
    }
    return ans;
  }
  int heightRight(TreeNode *node) {
    int ans = 0;
    while (node) {
      ans++;
      node = node->right;
    }
    return ans;
  }
  int dfs(TreeNode *node) {
    if (node == nullptr)
      return 0;
    int leftHeight = heightLeft(node);
    int rightHeight = heightRight(node);
    if (leftHeight == rightHeight)
      return (1 << leftHeight) - 1;
    return 1 + dfs(node->left) + dfs(node->right);
  }

public:
  int countNodes(TreeNode *root) { return dfs(root); }
};
