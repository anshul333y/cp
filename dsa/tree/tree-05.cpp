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

// ── Preorder Traversal ───────────────────────────────────────

// T: O(n)  S: O(h)
class Recursion {
private:
  void fun(TreeNode *node, vector<int> &ans) {
    if (node == nullptr)
      return;
    ans.push_back(node->val);
    fun(node->left, ans);
    fun(node->right, ans);
  }

public:
  vector<int> preorderTraversal(TreeNode *root) {
    vector<int> ans;
    fun(root, ans);
    return ans;
  }
};
