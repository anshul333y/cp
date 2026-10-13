#include <bits/stdc++.h>
using namespace std;

// ── Flood Fill ───────────────────────────────────────────────

// T: O(n*m) S: O(n*m)
class FloodFill {
private:
  void dfs(vector<vector<int>> &visited, vector<vector<int>> &grid, int i,
           int j, int color, vector<vector<int>> &result) {
    visited[i][j] = 1;
    result[i][j] = color;
    vector<vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    for (auto it : dir) {
      int row = i + it[0];
      int col = j + it[1];
      if (row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size()) {
        if (!visited[row][col] && grid[row][col] == grid[i][j])
          dfs(visited, grid, row, col, color, result);
      }
    }
  }

public:
  vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                                int color) {
    int n = image.size(), m = image[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));
    vector<vector<int>> result = image;
    dfs(visited, image, sr, sc, color, result);
    return result;
  }
};
