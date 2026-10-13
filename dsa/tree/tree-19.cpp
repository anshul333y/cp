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

// ── Zigzag Level Order Traversal ──────────────────────────────

// T: O(n)  S: O(w)
class Iterative {
public:
  vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    vector<vector<int>> ans;
    queue<TreeNode *> que;
    if (root)
      que.push(root);
    bool odd = true;
    while (!que.empty()) {
      int size = que.size();
      vector<int> temp(size);
      odd = !odd;
      int idx;
      if (odd)
        idx = size - 1;
      else
        idx = 0;
      while (size--) {
        TreeNode *node = que.front();
        que.pop();
        if (odd)
          temp[idx--] = node->val;
        else
          temp[idx++] = node->val;
        if (node->left)
          que.push(node->left);
        if (node->right)
          que.push(node->right);
      }
      ans.push_back(temp);
    }
    return ans;
  }
};
