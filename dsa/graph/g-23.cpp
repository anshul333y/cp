#include <bits/stdc++.h>
using namespace std;

// ── Detect Cycle in Directed Graph (Kahn's) ──────────────────

// T: O(V+E) S: O(V)
class DetectCycleDirectedKahns {
public:
  bool isCyclic(int V, vector<vector<int>> &edges) {
    vector<vector<int>> adj(V);
    vector<int> inDegree(V, 0);
    for (auto it : edges) {
      adj[it[0]].push_back(it[1]);
      inDegree[it[1]]++;
    }
    queue<int> que;
    for (int i = 0; i < V; i++) {
      if (!inDegree[i]) {
        que.push(i);
      }
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
    return V != ans.size();
  }
};
