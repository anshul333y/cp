#include <bits/stdc++.h>
using namespace std;

// ── Surrounded Regions ───────────────────────────────────────

// T: O(n*m) S: O(n*m)
class SurroundedRegions {
private:
  void dfs(vector<vector<int>> &visited, vector<vector<char>> &board, int row,
           int col) {
    int n = board.size(), m = board[0].size();
    visited[row][col] = 1;
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for (auto it : dir) {
      int newRow = row + it[0];
      int newCol = col + it[1];
      if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
          !visited[newRow][newCol] && board[newRow][newCol] == 'O')
        dfs(visited, board, newRow, newCol);
    }
  }

public:
  void solve(vector<vector<char>> &board) {
    int n = board.size(), m = board[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (!visited[i][j] && board[i][j] == 'O' &&
            (i == 0 || i == n - 1 || j == 0 || j == m - 1))
          dfs(visited, board, i, j);
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (!visited[i][j] && board[i][j] == 'O')
          board[i][j] = 'X';
      }
    }
  }
};
