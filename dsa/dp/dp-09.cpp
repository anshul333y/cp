#include <bits/stdc++.h>
using namespace std;

// ── Unique Paths II ──────────────────────────────────────────

// 1. Memoization (top-down DP)  |  T: O(m*n)  S: O(m*n)
class Memoization {
private:
  int rec(int row, int col, vector<vector<int>> &dp,
          vector<vector<int>> &obstacleGrid) {
    if (obstacleGrid[row][col])
      return 0;
    if (row == 0 && col == 0)
      return 1;
    if (dp[row][col] != -1)
      return dp[row][col];
    int left = 0, up = 0;
    if (col - 1 >= 0)
      left = rec(row, col - 1, dp, obstacleGrid);
    if (row - 1 >= 0)
      up = rec(row - 1, col, dp, obstacleGrid);
    return dp[row][col] = left + up;
  }

public:
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return rec(m - 1, n - 1, dp, obstacleGrid);
  }
};

// 2. Tabulation (bottom-up DP)  |  T: O(m*n)  S: O(m*n)
class Tabulation {
public:
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    for (int row = 0; row < m; row++) {
      for (int col = 0; col < n; col++) {
        if (obstacleGrid[row][col])
          dp[row][col] = 0;
        else if (row == 0 && col == 0)
          dp[row][col] = 1;
        else {
          int left = 0, up = 0;
          if (col - 1 >= 0)
            left = dp[row][col - 1];
          if (row - 1 >= 0)
            up = dp[row - 1][col];
          dp[row][col] = left + up;
        }
      }
    }
    return dp[m - 1][n - 1];
  }
};

// 3. Space Optimized            |  T: O(m*n)  S: O(n)
class SpaceOptimized {
public:
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    vector<int> dp(n, -1);
    for (int row = 0; row < m; row++) {
      for (int col = 0; col < n; col++) {
        if (obstacleGrid[row][col])
          dp[col] = 0;
        else if (row == 0 && col == 0)
          dp[col] = 1;
        else {
          int left = 0, up = 0;
          if (col - 1 >= 0)
            left = dp[col - 1];
          if (row - 1 >= 0)
            up = dp[col];
          dp[col] = left + up;
        }
      }
    }
    return dp[n - 1];
  }
};
