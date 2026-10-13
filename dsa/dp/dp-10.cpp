#include <bits/stdc++.h>
using namespace std;

// ── Minimum Path Sum ─────────────────────────────────────────

// 1. Memoization (top-down DP)  |  T: O(m*n)  S: O(m*n)
class Memoization {
private:
  int rec(int row, int col, vector<vector<int>> &dp,
          vector<vector<int>> &grid) {
    if (row == 0 && col == 0)
      return grid[row][col];
    if (dp[row][col] != -1)
      return dp[row][col];
    int left = INT_MAX, up = INT_MAX;
    if (col - 1 >= 0)
      left = rec(row, col - 1, dp, grid);
    if (row - 1 >= 0)
      up = rec(row - 1, col, dp, grid);
    return dp[row][col] = grid[row][col] + min(left, up);
  }

public:
  int minPathSum(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return rec(m - 1, n - 1, dp, grid);
  }
};

// 2. Tabulation (bottom-up DP)  |  T: O(m*n)  S: O(m*n)
class Tabulation {
public:
  int minPathSum(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    for (int row = 0; row < m; row++) {
      for (int col = 0; col < n; col++) {
        if (row == 0 && col == 0)
          dp[row][col] = grid[row][col];
        else {
          int left = INT_MAX, up = INT_MAX;
          if (col - 1 >= 0)
            left = dp[row][col - 1];
          if (row - 1 >= 0)
            up = dp[row - 1][col];
          dp[row][col] = grid[row][col] + min(left, up);
        }
      }
    }
    return dp[m - 1][n - 1];
  }
};

// 3. Space Optimized            |  T: O(m*n)  S: O(n)
class SpaceOptimized {
public:
  int minPathSum(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    vector<int> dp(n, -1);
    for (int row = 0; row < m; row++) {
      for (int col = 0; col < n; col++) {
        if (row == 0 && col == 0)
          dp[col] = grid[row][col];
        else {
          int left = INT_MAX, up = INT_MAX;
          if (col - 1 >= 0)
            left = dp[col - 1];
          if (row - 1 >= 0)
            up = dp[col];
          dp[col] = grid[row][col] + min(left, up);
        }
      }
    }
    return dp[n - 1];
  }
};
