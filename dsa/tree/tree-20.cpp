#include <bits/stdc++.h>
using namespace std;

class Node {
public:
  int data;
  Node *left, *right;
  Node(int val) {
    data = val;
    left = right = nullptr;
  }
};

// ── Boundary Traversal ────────────────────────────────────────

// T: O(n)  S: O(h)
class Recursion {
private:
  void dfs(Node *node, vector<int> &ans) {
    if (node == nullptr)
      return;
    if (node->left == nullptr && node->right == nullptr)
      ans.push_back(node->data);
    dfs(node->left, ans);
    dfs(node->right, ans);
  }

public:
  vector<int> boundaryTraversal(Node *root) {
    vector<int> ans;
    stack<int> stk;
    if (root == nullptr)
      return {};
    if (root->left == nullptr && root->right == nullptr)
      return {root->data};

    ans.push_back(root->data);

    Node *node = root->left;
    while (node) {
      if (node->left || node->right)
        ans.push_back(node->data);
      if (node->left)
        node = node->left;
      else
        node = node->right;
    }

    dfs(root, ans);

    node = root->right;
    while (node) {
      if (node->left || node->right)
        stk.push(node->data);
      if (node->right)
        node = node->right;
      else
        node = node->left;
    }
    while (!stk.empty()) {
      ans.push_back(stk.top());
      stk.pop();
    }
    return ans;
  }
};
