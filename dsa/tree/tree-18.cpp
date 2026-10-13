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

// ── Same Tree ─────────────────────────────────────────────────

// T: O(n)  S: O(h)
class Recursion {
private:
  bool dfs(TreeNode *p, TreeNode *q) {
    if (p == nullptr && q == nullptr)
      return true;
    if (p == nullptr || q == nullptr)
      return false;
    if (p->val != q->val)
      return false;
    if (dfs(p->left, q->left) == false)
      return false;
    if (dfs(p->right, q->right) == false)
      return false;
    return true;
  }

public:
  bool isSameTree(TreeNode *p, TreeNode *q) { return dfs(p, q); }
};
