#include <bits/stdc++.h>
using namespace std;

// ── Topological Sort (DFS) ───────────────────────────────────

// T: O(V+E) S: O(V)
class TopologicalSortDFS {
private:
  void dfs(vector<int> &vis, vector<vector<int>> &adj, int node,
           stack<int> &stk) {
    vis[node] = 1;
    for (auto it : adj[node]) {
      if (!vis[it])
        dfs(vis, adj, it, stk);
    }
    stk.push(node);
  }

public:
  vector<int> topoSort(int V, vector<vector<int>> &edges) {
    vector<vector<int>> adj(V);
    for (auto it : edges) {
      adj[it[0]].push_back(it[1]);
    }
    vector<int> vis(V, 0);
    stack<int> stk;
    for (int i = 0; i < V; i++) {
      if (!vis[i]) {
        dfs(vis, adj, i, stk);
      }
    }
    vector<int> ans;
    while (!stk.empty()) {
      ans.push_back(stk.top());
      stk.pop();
    }
    return ans;
  }
};
