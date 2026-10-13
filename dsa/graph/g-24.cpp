#include <bits/stdc++.h>
using namespace std;

// ── Course Schedule I ────────────────────────────────────────

// T: O(V+E) S: O(V)
class CourseScheduleI {
public:
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    int V = numCourses;
    vector<vector<int>> adj(V);
    vector<int> inDegree(V, 0);
    for (auto it : prerequisites) {
      adj[it[1]].push_back(it[0]);
      inDegree[it[0]]++;
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
    return V == ans.size();
  }
};

// ── Course Schedule II ───────────────────────────────────────

// T: O(V+E) S: O(V)
class CourseScheduleII {
public:
  vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
    int V = numCourses;
    vector<vector<int>> adj(V);
    vector<int> inDegree(V, 0);
    for (auto it : prerequisites) {
      adj[it[1]].push_back(it[0]);
      inDegree[it[0]]++;
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
    if (V == ans.size())
      return ans;
    else
      return {};
  }
};
