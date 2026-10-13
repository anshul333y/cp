#include <bits/stdc++.h>
using namespace std;

// ── Number of Enclaves ───────────────────────────────────────

// T: O(n*m) S: O(n*m)
class NumberOfEnclaves {
private:
  void dfs(vector<vector<int>> &visited, vector<vector<int>> &grid, int row,
           int col) {
    int n = grid.size(), m = grid[0].size();
    visited[row][col] = 1;
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for (auto it : dir) {
      int newRow = row + it[0];
      int newCol = col + it[1];
      if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
          !visited[newRow][newCol] && grid[newRow][newCol] == 1)
        dfs(visited, grid, newRow, newCol);
    }
  }

public:
  int numEnclaves(vector<vector<int>> &grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (!visited[i][j] && grid[i][j] == 1 &&
            (i == 0 || i == n - 1 || j == 0 || j == m - 1))
          dfs(visited, grid, i, j);
      }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (!visited[i][j] && grid[i][j] == 1)
          ans++;
      }
    }
    return ans;
  }
};
