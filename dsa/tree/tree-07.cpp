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

// ── Postorder Traversal ──────────────────────────────────────

// T: O(n)  S: O(h)
class Recursion {
private:
  void fun(TreeNode *node, vector<int> &ans) {
    if (node == nullptr)
      return;
    fun(node->left, ans);
    fun(node->right, ans);
    ans.push_back(node->val);
  }

public:
  vector<int> postorderTraversal(TreeNode *root) {
    vector<int> ans;
    fun(root, ans);
    return ans;
  }
};
