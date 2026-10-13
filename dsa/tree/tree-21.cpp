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

// ── Vertical Order Traversal ──────────────────────────────────

// T: O(n log n)  S: O(n)
class Recursion {
private:
  void dfs(TreeNode *node, map<int, map<int, multiset<int>>> &nodes, int col,
           int row) {
    if (node == nullptr)
      return;
    nodes[col][row].insert(node->val);
    dfs(node->left, nodes, col - 1, row + 1);
    dfs(node->right, nodes, col + 1, row + 1);
  }

public:
  vector<vector<int>> verticalTraversal(TreeNode *root) {
    vector<vector<int>> ans;
    map<int, map<int, multiset<int>>> nodes;
    dfs(root, nodes, 0, 0);
    for (auto &p : nodes) {
      vector<int> temp;
      for (auto &q : p.second) {
        for (auto it : q.second)
          temp.push_back(it);
      }
      ans.push_back(temp);
    }
    return ans;
  }
};
