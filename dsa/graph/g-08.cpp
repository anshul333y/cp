#include <bits/stdc++.h>
using namespace std;

// ── Number of Islands ────────────────────────────────────────

// T: O(n*m) S: O(n*m)
class NumberOfIslands {
private:
  void dfs(vector<vector<int>> &visited, vector<vector<char>> &grid, int i,
           int j) {
    visited[i][j] = 1;
    vector<vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    for (auto it : dir) {
      int row = i + it[0];
      int col = j + it[1];
      if (row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size()) {
        if (!visited[row][col] && grid[row][col] == '1')
          dfs(visited, grid, row, col);
      }
    }
  }

public:
  int numIslands(vector<vector<char>> &grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));
    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (!visited[i][j] && grid[i][j] == '1') {
          ans++;
          dfs(visited, grid, i, j);
        }
      }
    }
    return ans;
  }
};
