#include <bits/stdc++.h>
using namespace std;

// ── Unique Paths ─────────────────────────────────────────────

// 1. Memoization (top-down DP)  |  T: O(m*n)  S: O(m*n)
class Memoization {
private:
  int rec(int row, int col, vector<vector<int>> &dp) {
    if (row == 0 || col == 0)
      return 1;
    if (dp[row][col] != -1)
      return dp[row][col];
    int left = rec(row, col - 1, dp);
    int up = rec(row - 1, col, dp);
    return dp[row][col] = left + up;
  }

public:
  int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return rec(m - 1, n - 1, dp);
  }
};

// 2. Tabulation (bottom-up DP)  |  T: O(m*n)  S: O(m*n)
class Tabulation {
public:
  int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, -1));
    for (int row = 0; row < m; row++) {
      for (int col = 0; col < n; col++) {
        if (row == 0 || col == 0)
          dp[row][col] = 1;
        else {
          int left = dp[row][col - 1];
          int up = dp[row - 1][col];
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
  int uniquePaths(int m, int n) {
    vector<int> dp(n, -1);
    for (int row = 0; row < m; row++) {
      for (int col = 0; col < n; col++) {
        if (row == 0 || col == 0)
          dp[col] = 1;
        else {
          int up = dp[col];
          int left = dp[col - 1];
          dp[col] = left + up;
        }
      }
    }
    return dp[n - 1];
  }
};
