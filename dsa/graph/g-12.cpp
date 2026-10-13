#include <bits/stdc++.h>
using namespace std;

// ── Detect Cycle in Undirected Graph (DFS) ───────────────────

// T: O(V+2E) S: O(V)
class DetectCycleDFS {
private:
  bool dfs(vector<vector<int>> &adj, vector<int> &visited, int node,
           int parent) {
    visited[node] = 1;
    for (auto it : adj[node]) {
      if (!visited[it]) {
        if (dfs(adj, visited, it, node))
          return true;
      } else if (it != parent)
        return true;
    }
    return false;
  }

public:
  bool isCycle(int V, vector<vector<int>> &edges) {
    vector<int> visited(V, 0);
    vector<vector<int>> adj(V);
    for (auto it : edges) {
      adj[it[0]].push_back(it[1]);
      adj[it[1]].push_back(it[0]);
    }
    for (int i = 0; i < V; i++) {
      if (!visited[i]) {
        if (dfs(adj, visited, i, -1))
          return true;
      }
    }
    return false;
  }
};
