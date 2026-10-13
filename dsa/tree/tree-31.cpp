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

// ── Amount of Time for Binary Tree to Be Infected ─────────────

// T: O(n)  S: O(n)
class Recursion {
private:
  void dfs(TreeNode *node, TreeNode *parent,
           unordered_map<int, TreeNode *> &parentStore, TreeNode *&target,
           int start) {
    if (node == nullptr)
      return;
    if (parent)
      parentStore[node->val] = parent;
    if (node->val == start)
      target = node;
    dfs(node->left, node, parentStore, target, start);
    dfs(node->right, node, parentStore, target, start);
  }

public:
  int amountOfTime(TreeNode *root, int start) {
    unordered_map<int, TreeNode *> parentStore;
    TreeNode *target = nullptr;
    dfs(root, nullptr, parentStore, target, start);

    queue<TreeNode *> que;
    vector<bool> visited(1e5 + 1, false);
    if (target) {
      que.push(target);
      visited[target->val] = true;
    }

    int level = -1;
    while (!que.empty()) {
      level++;
      int size = que.size();
      while (size--) {
        TreeNode *node = que.front();
        que.pop();
        if (node->left && !visited[node->left->val]) {
          que.push(node->left);
          visited[node->left->val] = true;
        }
        if (node->right && !visited[node->right->val]) {
          que.push(node->right);
          visited[node->right->val] = true;
        }
        if (parentStore.find(node->val) != parentStore.end() &&
            !visited[parentStore[node->val]->val]) {
          que.push(parentStore[node->val]);
          visited[parentStore[node->val]->val] = true;
        }
      }
    }
    return level;
  }
};
