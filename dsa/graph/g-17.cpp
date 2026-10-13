#include <bits/stdc++.h>
using namespace std;

// ── Bipartite Graph (DFS) ────────────────────────────────────

// T: O(V+2E) S: O(V)
class BipartiteGraphDFS {
private:
  bool dfs(int col, vector<int> &vis, vector<vector<int>> &graph, int node) {
    vis[node] = col;
    for (auto it : graph[node]) {
      if (vis[it] == -1) {
        if (!dfs(!vis[node], vis, graph, it))
          return false;
      } else if (vis[node] == vis[it])
        return false;
    }
    return true;
  }

public:
  bool isBipartite(vector<vector<int>> &graph) {
    int n = graph.size();
    vector<int> vis(n, -1);
    for (int i = 0; i < n; i++) {
      if (vis[i] == -1) {
        if (!dfs(0, vis, graph, i))
          return false;
      }
    }
    return true;
  }
};
