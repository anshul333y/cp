#include <bits/stdc++.h>
using namespace std;

// ── Bipartite Graph (BFS) ────────────────────────────────────

// T: O(V+2E) S: O(V)
class BipartiteGraphBFS {
private:
  bool bfs(int col, vector<int> &vis, vector<vector<int>> &graph, int node) {
    vis[node] = col;
    queue<int> que;
    que.push(node);
    while (!que.empty()) {
      node = que.front();
      que.pop();
      for (auto it : graph[node]) {
        if (vis[it] == -1) {
          vis[it] = !vis[node];
          que.push(it);
        } else if (vis[node] == vis[it])
          return false;
      }
    }
    return true;
  }

public:
  bool isBipartite(vector<vector<int>> &graph) {
    int n = graph.size();
    vector<int> vis(n, -1);
    for (int i = 0; i < n; i++) {
      if (vis[i] == -1) {
        if (!bfs(0, vis, graph, i))
          return false;
      }
    }
    return true;
  }
};
