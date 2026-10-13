#include <bits/stdc++.h>
using namespace std;

// ── Alien Dictionary ─────────────────────────────────────────

// T: O(N*L + V+E) S: O(V+E)
class AlienDictionary {
private:
  bool dfs(vector<int> &vis, vector<int> &pathVis, vector<vector<int>> &adj,
           int node, stack<int> &stk) {
    vis[node] = 1;
    pathVis[node] = 1;
    for (auto it : adj[node]) {
      if (!vis[it]) {
        if (dfs(vis, pathVis, adj, it, stk))
          return true;
      } else if (pathVis[it])
        return true;
    }
    pathVis[node] = 0;
    stk.push(node);
    return false;
  }

public:
  string findOrder(vector<string> &words) {
    int n = words.size();
    vector<vector<int>> adj(26);
    vector<int> present(26, 0);
    for (auto &word : words) {
      for (char c : word) {
        present[c - 'a'] = 1;
      }
    }
    for (int i = 1; i < n; i++) {
      bool found = false;
      string a = words[i - 1];
      string b = words[i];
      int size = min(a.size(), b.size());
      for (int idx = 0; idx < size; idx++) {
        if (a[idx] != b[idx]) {
          adj[a[idx] - 'a'].push_back(b[idx] - 'a');
          found = true;
          break;
        }
      }
      if (!found && a.size() > b.size())
        return "";
    }
    vector<int> vis(26, 0), pathVis(26, 0);
    stack<int> stk;
    for (int i = 0; i < 26; i++) {
      if (present[i] && !vis[i]) {
        if (dfs(vis, pathVis, adj, i, stk))
          return "";
      }
    }
    string ans;
    while (!stk.empty()) {
      ans.push_back(stk.top() + 'a');
      stk.pop();
    }
    return ans;
  }
};
