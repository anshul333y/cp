#include <bits/stdc++.h>
using namespace std;

// ── Minimum Falling Path Sum ─────────────────────────────────

// 1. Memoization (top-down DP)  |  T: O(m*n)  S: O(m*n)
class Memoization {
private:
  int rec(int row, int col, vector<vector<int>> &matrix,
          vector<vector<int>> &dp) {
    if (row == 0)
      return matrix[row][col];
    if (dp[row][col] != INT_MAX)
      return dp[row][col];
    int downLeft, down, downRight;
    downLeft = down = downRight = INT_MAX;
    if (col - 1 >= 0)
      downLeft = rec(row - 1, col - 1, matrix, dp);
    down = rec(row - 1, col, matrix, dp);
    if (col + 1 <= matrix[row].size() - 1)
      downRight = rec(row - 1, col + 1, matrix, dp);
    return dp[row][col] = matrix[row][col] + min({downLeft, down, downRight});
  }

public:
  int minFallingPathSum(vector<vector<int>> &matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
      ans = min(ans, rec(m - 1, i, matrix, dp));
    return ans;
  }
};

// 2. Tabulation (bottom-up DP)  |  T: O(m*n)  S: O(m*n)
class Tabulation {
public:
  int minFallingPathSum(vector<vector<int>> &matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
    int ans = INT_MAX;
    for (int row = 0; row < m; row++) {
      for (int col = 0; col < n; col++) {
        if (row == 0)
          dp[row][col] = matrix[row][col];
        else {
          int downLeft, down, downRight;
          downLeft = down = downRight = INT_MAX;
          if (col - 1 >= 0)
            downLeft = dp[row - 1][col - 1];
          down = dp[row - 1][col];
          if (col + 1 <= n - 1)
            downRight = dp[row - 1][col + 1];
          dp[row][col] = matrix[row][col] + min({downLeft, down, downRight});
        }
        if (row == m - 1)
          ans = min(ans, dp[row][col]);
      }
    }
    return ans;
  }
};

// 3. Space Optimized            |  T: O(m*n)  S: O(n)
class SpaceOptimized {
public:
  int minFallingPathSum(vector<vector<int>> &matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<int> dp(n, INT_MAX);
    int ans = INT_MAX;
    for (int row = 0; row < m; row++) {
      vector<int> temp(n, INT_MAX);
      for (int col = 0; col < n; col++) {
        if (row == 0)
          temp[col] = matrix[row][col];
        else {
          int downLeft, down, downRight;
          downLeft = down = downRight = INT_MAX;
          if (col - 1 >= 0)
            downLeft = dp[col - 1];
          down = dp[col];
          if (col + 1 <= n - 1)
            downRight = dp[col + 1];
          temp[col] = matrix[row][col] + min({downLeft, down, downRight});
        }
        if (row == m - 1)
          ans = min(ans, temp[col]);
      }
      dp = temp;
    }
    return ans;
  }
};
