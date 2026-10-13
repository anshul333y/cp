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

// ── All Traversals (Single Pass) ─────────────────────────────

// T: O(n)  S: O(h)
class Iterative {
public:
  tuple<vector<int>, vector<int>, vector<int>> traversal(TreeNode *root) {
    vector<int> preOrder, inOrder, postOrder;
    stack<pair<TreeNode *, int>> stk;
    if (root)
      stk.push({root, 1});
    while (!stk.empty()) {
      auto it = stk.top();
      stk.pop();
      if (it.second == 1) {
        preOrder.push_back(it.first->val);
        it.second++;
        stk.push(it);
        if (it.first->left)
          stk.push({it.first->left, 1});
      } else if (it.second == 2) {
        inOrder.push_back(it.first->val);
        it.second++;
        stk.push(it);
        if (it.first->right)
          stk.push({it.first->right, 1});
      } else {
        postOrder.push_back(it.first->val);
      }
    }
    return {preOrder, inOrder, postOrder};
  }
};
