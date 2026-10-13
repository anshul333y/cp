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

// ── All Nodes Distance K in Binary Tree ───────────────────────

// T: O(n)  S: O(n)
class Recursion {
private:
  void dfs(TreeNode *node, TreeNode *parent,
           unordered_map<int, TreeNode *> &parentStore) {
    if (node == nullptr)
      return;
    if (parent)
      parentStore[node->val] = parent;
    dfs(node->left, node, parentStore);
    dfs(node->right, node, parentStore);
  }

public:
  vector<int> distanceK(TreeNode *root, TreeNode *target, int k) {
    unordered_map<int, TreeNode *> parentStore;
    dfs(root, nullptr, parentStore);

    queue<TreeNode *> que;
    vector<bool> visited(501, false);
    if (root) {
      que.push(target);
      visited[target->val] = true;
    }

    int level = -1;
    while (!que.empty()) {
      level++;
      int size = que.size();
      if (level == k)
        break;
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

    vector<int> ans;
    while (!que.empty()) {
      TreeNode *node = que.front();
      ans.push_back(node->val);
      que.pop();
    }
    return ans;
  }
};
