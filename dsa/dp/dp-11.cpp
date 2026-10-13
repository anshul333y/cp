#include <bits/stdc++.h>
using namespace std;

// ── Triangle Minimum Path Sum ────────────────────────────────

// 1. Memoization (top-down DP)  |  T: O(m²)  S: O(m²)
class Memoization {
private:
  int rec(int row, int col, vector<vector<int>> &dp,
          vector<vector<int>> &triangle) {
    if (row == (int)triangle.size() - 1)
      return triangle[row][col];
    if (dp[row][col] != INT_MAX)
      return dp[row][col];
    int downRight = rec(row + 1, col + 1, dp, triangle);
    int down = rec(row + 1, col, dp, triangle);
    return dp[row][col] = triangle[row][col] + min(downRight, down);
  }

public:
  int minimumTotal(vector<vector<int>> &triangle) {
    int m = triangle.size();
    vector<vector<int>> dp(m, vector<int>(m, INT_MAX));
    return rec(0, 0, dp, triangle);
  }
};

// 2. Tabulation (bottom-up DP)  |  T: O(m²)  S: O(m²)
class Tabulation {
public:
  int minimumTotal(vector<vector<int>> &triangle) {
    int m = triangle.size();
    vector<vector<int>> dp(m, vector<int>(m, INT_MAX));
    for (int row = m - 1; row >= 0; row--) {
      for (int col = 0; col <= row; col++) {
        if (row == m - 1)
          dp[row][col] = triangle[row][col];
        else {
          int downRight = dp[row + 1][col + 1];
          int down = dp[row + 1][col];
          dp[row][col] = triangle[row][col] + min(downRight, down);
        }
      }
    }
    return dp[0][0];
  }
};

// 3. Space Optimized            |  T: O(m²)  S: O(m)
class SpaceOptimized {
public:
  int minimumTotal(vector<vector<int>> &triangle) {
    int m = triangle.size();
    vector<int> dp(m, INT_MAX);
    for (int row = m - 1; row >= 0; row--) {
      for (int col = 0; col <= row; col++) {
        if (row == m - 1)
          dp[col] = triangle[row][col];
        else {
          int downRight = dp[col + 1];
          int down = dp[col];
          dp[col] = triangle[row][col] + min(downRight, down);
        }
      }
    }
    return dp[0];
  }
};
