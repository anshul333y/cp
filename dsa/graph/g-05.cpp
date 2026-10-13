#include <bits/stdc++.h>
using namespace std;

// ── BFS Traversal ────────────────────────────────────────────

// T: O(V+2E) S: O(V)
class BFSTraversal {
private:
  void bfs(queue<int> &que, vector<int> &visited, vector<vector<int>> &adj,
           vector<int> &ans) {
    while (!que.empty()) {
      int parent = que.front();
      que.pop();
      ans.push_back(parent);
      for (int child : adj[parent]) {
        if (!visited[child]) {
          visited[child] = 1;
          que.push(child);
        }
      }
    }
  }

public:
  vector<int> bfs(vector<vector<int>> &adj) {
    int n = adj.size();
    vector<int> visited(n, 0);
    queue<int> que;
    visited[0] = 1;
    que.push(0);
    vector<int> ans;
    bfs(que, visited, adj, ans);
    return ans;
  }
};
