#include <bits/stdc++.h>
using namespace std;

// ── DFS Traversal ────────────────────────────────────────────

// T: O(V+2E) S: O(V)
class DFSTraversal {
private:
  void dfs(vector<int> &visited, vector<vector<int>> &adj, vector<int> &ans,
           int node) {
    visited[node] = 1;
    ans.push_back(node);
    for (auto child : adj[node]) {
      if (!visited[child])
        dfs(visited, adj, ans, child);
    }
  }

public:
  vector<int> dfs(vector<vector<int>> &adj) {
    int n = adj.size();
    vector<int> visited(n, 0);
    vector<int> ans;
    dfs(visited, adj, ans, 0);
    return ans;
  }
};
