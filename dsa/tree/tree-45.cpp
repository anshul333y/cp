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

// ── Kth Smallest Element in a BST ─────────────────────────────

// T: O(n log n)  S: O(n)
class Recursion {
private:
  void rec(TreeNode *node,
           priority_queue<int, vector<int>, greater<int>> &heap) {
    if (node == nullptr)
      return;
    heap.push(node->val);
    rec(node->left, heap);
    rec(node->right, heap);
  }

public:
  int kthSmallest(TreeNode *root, int k) {
    priority_queue<int, vector<int>, greater<int>> heap;
    rec(root, heap);
    int count = k, ans = 0;
    while (count--) {
      ans = heap.top();
      heap.pop();
    }
    return ans;
  }
};

// T: O(h + k)  S: O(h)
class InorderEarlyStop {
private:
  int ans;
  int count = 0;
  void rec(TreeNode *node, int k) {
    if (node == nullptr)
      return;
    rec(node->left, k);
    count++;
    if (count == k) {
      ans = node->val;
      return;
    }
    rec(node->right, k);
  }

public:
  int kthSmallest(TreeNode *root, int k) {
    rec(root, k);
    return ans;
  }
};
