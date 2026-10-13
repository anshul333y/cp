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

// ── Binary Tree Paths ──────────────────────────────────────────

// T: O(n)  S: O(h)
class Recursion {
private:
  void dfs(TreeNode *node, vector<string> &ans, string &temp) {
    if (node == nullptr)
      return;
    int len = temp.size();
    temp += to_string(node->val);
    if (node->left == nullptr && node->right == nullptr)
      ans.push_back(temp);
    else {
      temp.push_back('-');
      temp.push_back('>');
      dfs(node->left, ans, temp);
      dfs(node->right, ans, temp);
      temp.pop_back();
      temp.pop_back();
    }
    temp.resize(len);
  }

public:
  vector<string> binaryTreePaths(TreeNode *root) {
    vector<string> ans;
    string temp;
    dfs(root, ans, temp);
    return ans;
  }
};
