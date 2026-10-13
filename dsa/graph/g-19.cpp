#include <bits/stdc++.h>
using namespace std;

// ── Detect Cycle in Directed Graph (DFS) ─────────────────────

// T: O(V+E) S: O(V)
class DetectCycleDirectedDFS {
private:
  bool dfs(vector<int> &vis, vector<int> &pathVis, vector<vector<int>> &adj,
           int node) {
    vis[node] = 1;
    pathVis[node] = 1;
    for (auto it : adj[node]) {
      if (!vis[it]) {
        if (dfs(vis, pathVis, adj, it))
          return true;
      } else if (pathVis[it])
        return true;
    }
    pathVis[node] = 0;
    return false;
  }

public:
  bool isCyclic(int V, vector<vector<int>> &edges) {
    vector<vector<int>> adj(V);
    for (auto it : edges) {
      adj[it[0]].push_back(it[1]);
    }
    vector<int> vis(V, 0), pathVis(V, 0);
    for (int i = 0; i < V; i++) {
      if (!vis[i]) {
        if (dfs(vis, pathVis, adj, i))
          return true;
      }
    }
    return false;
  }
};
