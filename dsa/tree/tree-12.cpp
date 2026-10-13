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
class Iterative {
public:
  vector<int> postorderTraversal(TreeNode *root) {
    vector<int> ans;
    stack<TreeNode *> stk;
    TreeNode *curr = root;
    while (curr || !stk.empty()) {
      if (curr) {
        stk.push(curr);
        curr = curr->left;
      } else {
        TreeNode *node = stk.top()->right;
        if (node == nullptr) {
          node = stk.top();
          ans.push_back(node->val);
          stk.pop();
          while (!stk.empty() && stk.top()->right == node) {
            node = stk.top();
            ans.push_back(node->val);
            stk.pop();
          }
        } else {
          curr = node;
        }
      }
    }
    return ans;
  }
};
