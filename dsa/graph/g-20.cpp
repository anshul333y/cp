#include <bits/stdc++.h>
using namespace std;

// ── Eventual Safe Nodes ──────────────────────────────────────

// T: O(V+E) S: O(V)
class EventualSafeNodes {
private:
  bool dfs(vector<int> &vis, vector<int> &pathVis, vector<vector<int>> &adj,
           int node, vector<int> &safe) {
    vis[node] = 1;
    pathVis[node] = 1;
    for (auto it : adj[node]) {
      if (!vis[it]) {
        if (dfs(vis, pathVis, adj, it, safe))
          return true;
      } else if (pathVis[it])
        return true;
    }
    safe[node] = 1;
    pathVis[node] = 0;
    return false;
  }

public:
  vector<int> eventualSafeNodes(vector<vector<int>> &graph) {
    int V = graph.size();
    vector<int> vis(V, 0), pathVis(V, 0), safe(V, 0);
    for (int i = 0; i < V; i++) {
      if (!vis[i]) {
        dfs(vis, pathVis, graph, i, safe);
      }
    }
    vector<int> ans;
    for (int i = 0; i < V; i++) {
      if (safe[i])
        ans.push_back(i);
    }
    return ans;
  }
};
