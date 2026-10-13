#include <bits/stdc++.h>
using namespace std;

// ── Count Distinct Islands ───────────────────────────────────

// T: O(n*m) S: O(n*m)
class CountDistinctIslands {
private:
  void dfs(vector<vector<int>> &visited, vector<vector<char>> &grid, int i,
           int j, vector<pair<int, int>> &ans, int i0, int j0) {
    visited[i][j] = 1;
    ans.push_back({i - i0, j - j0});
    vector<vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    for (auto it : dir) {
      int row = i + it[0];
      int col = j + it[1];
      if (row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size()) {
        if (!visited[row][col] && grid[row][col] == 'L')
          dfs(visited, grid, row, col, ans, i0, j0);
      }
    }
  }

public:
  int countDistinctIslands(vector<vector<char>> &grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));
    set<vector<pair<int, int>>> st;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (!visited[i][j] && grid[i][j] == 'L') {
          vector<pair<int, int>> ans;
          dfs(visited, grid, i, j, ans, i, j);
          st.insert(ans);
        }
      }
    }
    return st.size();
  }
};
