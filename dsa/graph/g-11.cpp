#include <bits/stdc++.h>
using namespace std;

// ── Detect Cycle in Undirected Graph (BFS) ───────────────────

// T: O(V+2E) S: O(V)
class DetectCycleBFS {
private:
  bool bfs(vector<vector<int>> &adj, vector<int> &visited, int node) {
    visited[node] = 1;
    queue<pair<int, int>> que;
    que.push({node, -1});
    while (!que.empty()) {
      int node = que.front().first;
      int parent = que.front().second;
      que.pop();
      for (auto it : adj[node]) {
        if (!visited[it]) {
          visited[it] = 1;
          que.push({it, node});
        } else if (it != parent)
          return true;
      }
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
        if (bfs(adj, visited, i))
          return true;
      }
    }
    return false;
  }
};
