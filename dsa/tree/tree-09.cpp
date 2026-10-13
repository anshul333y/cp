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
class Iterative {
public:
  vector<int> preorderTraversal(TreeNode *root) {
    vector<int> ans;
    stack<TreeNode *> stk;
    if (root)
      stk.push(root);
    while (!stk.empty()) {
      TreeNode *node = stk.top();
      stk.pop();
      ans.push_back(node->val);
      if (node->right)
        stk.push(node->right);
      if (node->left)
        stk.push(node->left);
    }
    return ans;
  }
};
