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

// ── Binary Tree Right Side View ───────────────────────────────

// T: O(n)  S: O(h)
class Recursion {
private:
  void dfs(TreeNode *node, int level, vector<int> &ans) {
    if (node == nullptr)
      return;
    if (ans.size() == level)
      ans.push_back(node->val);
    dfs(node->right, level + 1, ans);
    dfs(node->left, level + 1, ans);
  }

public:
  vector<int> rightSideView(TreeNode *root) {
    vector<int> ans;
    dfs(root, 0, ans);
    return ans;
  }
};

// T: O(n)  S: O(w)
class Iterative {
public:
  vector<int> rightSideView(TreeNode *root) {
    vector<int> ans;
    queue<TreeNode *> que;
    if (root)
      que.push(root);
    while (!que.empty()) {
      int size = que.size();
      for (int i = 0; i < size; i++) {
        TreeNode *node = que.front();
        que.pop();
        if (i == size - 1)
          ans.push_back(node->val);
        if (node->left)
          que.push(node->left);
        if (node->right)
          que.push(node->right);
      }
    }
    return ans;
  }
};
