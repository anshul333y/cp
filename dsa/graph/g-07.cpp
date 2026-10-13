#include <bits/stdc++.h>
using namespace std;

// ── Number of Provinces ──────────────────────────────────────

// T: O(V+2E) S: O(V)
class NumberOfProvinces {
private:
  void dfs(vector<int> &visited, vector<vector<int>> &adj, int node) {
    visited[node] = 1;
    for (auto child : adj[node]) {
      if (!visited[child])
        dfs(visited, adj, child);
    }
  }

public:
  int findCircleNum(vector<vector<int>> &isConnected) {
    int n = isConnected.size();
    int m = isConnected[0].size();
    vector<int> visited(n, 0);
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (isConnected[i][j]) {
          adj[i].push_back(j);
          adj[j].push_back(i);
        }
      }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (!visited[i]) {
        ans++;
        dfs(visited, adj, i);
      }
    }
    return ans;
  }
};
