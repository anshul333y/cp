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

// ── Maximum Width of Binary Tree ──────────────────────────────

// T: O(n)  S: O(w)
class Iterative {
public:
  int widthOfBinaryTree(TreeNode *root) {
    long long ans = 0;
    queue<pair<TreeNode *, long long>> que;
    if (root)
      que.push({root, 0});
    while (!que.empty()) {
      int size = que.size();
      long long first = que.front().second, last;
      while (size--) {
        TreeNode *node = que.front().first;
        long long curr = que.front().second - first;
        last = curr;
        que.pop();
        if (node->left)
          que.push({node->left, 2 * curr + 1});
        if (node->right)
          que.push({node->right, 2 * curr + 2});
      }
      ans = max(ans, last + 1);
    }
    return ans;
  }
};
