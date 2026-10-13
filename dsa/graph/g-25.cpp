#include <bits/stdc++.h>
using namespace std;

// ── Eventual Safe Nodes (Kahn's) ─────────────────────────────

// T: O(V+E) S: O(V)
class EventualSafeNodesKahns {
public:
  vector<int> eventualSafeNodes(vector<vector<int>> &graph) {
    int n = graph.size();
    vector<vector<int>> adj(n);
    vector<int> inDegree(n, 0);
    for (int i = 0; i < n; i++) {
      for (auto it : graph[i]) {
        adj[it].push_back(i);
        inDegree[i]++;
      }
    }
    queue<int> que;
    for (int i = 0; i < n; i++) {
      if (!inDegree[i])
        que.push(i);
    }
    vector<int> ans;
    while (!que.empty()) {
      int node = que.front();
      que.pop();
      ans.push_back(node);
      for (auto it : adj[node]) {
        inDegree[it]--;
        if (!inDegree[it])
          que.push(it);
      }
    }
    sort(ans.begin(), ans.end());
    return ans;
  }
};
