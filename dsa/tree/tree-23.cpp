#include <bits/stdc++.h>
using namespace std;

class Node {
public:
  int data;
  Node *left;
  Node *right;
  Node(int val) {
    data = val;
    left = right = nullptr;
  }
};

// ── Bottom View of Binary Tree ────────────────────────────────

// T: O(n log n)  S: O(n)
class Iterative {
public:
  vector<int> bottomView(Node *root) {
    vector<int> ans;
    map<int, int> nodes;
    queue<pair<Node *, int>> que;
    if (root)
      que.push({root, 0});
    while (!que.empty()) {
      Node *node = que.front().first;
      int col = que.front().second;
      que.pop();
      nodes[col] = node->data;
      if (node->left)
        que.push({node->left, col - 1});
      if (node->right)
        que.push({node->right, col + 1});
    }
    for (auto &p : nodes) {
      ans.push_back(p.second);
    }
    return ans;
  }
};

// T: O(n log n)  S: O(n)
class Recursion {
private:
  void dfs(Node *node, map<int, pair<int, int>> &nodes, int col, int row) {
    if (node == nullptr)
      return;
    if (nodes.find(col) == nodes.end() || nodes[col].first <= row)
      nodes[col] = {row, node->data};
    dfs(node->left, nodes, col - 1, row + 1);
    dfs(node->right, nodes, col + 1, row + 1);
  }

public:
  vector<int> bottomView(Node *root) {
    vector<int> ans;
    map<int, pair<int, int>> nodes;
    dfs(root, nodes, 0, 0);
    for (auto &p : nodes) {
      ans.push_back(p.second.second);
    }
    return ans;
  }
};
