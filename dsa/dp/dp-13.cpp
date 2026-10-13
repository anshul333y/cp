#include <bits/stdc++.h>
using namespace std;

// ── Cherry Pickup II ─────────────────────────────────────────

// 1. Memoization (top-down DP)  |  T: O(m*n²)  S: O(m*n²)
class Memoization {
private:
  int rec(int row, int col1, int col2, vector<vector<int>> &grid,
          vector<vector<vector<int>>> &dp) {
    if (col1 < 0 || col1 >= grid[0].size() || col2 < 0 ||
        col2 >= grid[0].size())
      return INT_MIN;
    if (row == grid.size() - 1) {
      if (col1 == col2)
        return grid[row][col1];
      else
        return grid[row][col1] + grid[row][col2];
    }
    if (dp[row][col1][col2] != -1)
      return dp[row][col1][col2];
    vector<int> move = {-1, 0, 1};
    int ans = INT_MIN;
    for (auto it1 : move) {
      for (auto it2 : move) {
        int value;
        if (col1 == col2)
          value =
              grid[row][col1] + rec(row + 1, col1 + it1, col2 + it2, grid, dp);
        else
          value = grid[row][col1] + grid[row][col2] +
                  rec(row + 1, col1 + it1, col2 + it2, grid, dp);
        ans = max(ans, value);
      }
    }
    return dp[row][col1][col2] = ans;
  }

public:
  int cherryPickup(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<vector<int>>> dp(m,
                                   vector<vector<int>>(n, vector<int>(n, -1)));
    return rec(0, 0, n - 1, grid, dp);
  }
};

// 2. Tabulation (bottom-up DP)  |  T: O(m*n²)  S: O(m*n²)
class Tabulation {
public:
  int cherryPickup(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<vector<int>>> dp(m,
                                   vector<vector<int>>(n, vector<int>(n, -1)));
    for (int row = m - 1; row >= 0; row--) {
      for (int col1 = 0; col1 < n; col1++) {
        for (int col2 = 0; col2 < n; col2++) {
          if (row == m - 1) {
            if (col1 == col2)
              dp[row][col1][col2] = grid[row][col1];
            else
              dp[row][col1][col2] = grid[row][col1] + grid[row][col2];
          } else {
            vector<int> move = {-1, 0, 1};
            int ans = INT_MIN;
            for (auto it1 : move) {
              for (auto it2 : move) {
                int value;
                if (col1 == col2)
                  value = grid[row][col1];
                else
                  value = grid[row][col1] + grid[row][col2];
                if (col1 + it1 >= 0 && col1 + it1 <= n - 1 && col2 + it2 >= 0 &&
                    col2 + it2 <= n - 1)
                  value += dp[row + 1][col1 + it1][col2 + it2];
                else
                  value = INT_MIN;
                ans = max(ans, value);
              }
            }
            dp[row][col1][col2] = ans;
          }
        }
      }
    }
    return dp[0][0][n - 1];
  }
};

// 3. Space Optimized            |  T: O(m*n²)  S: O(n²)
class SpaceOptimized {
public:
  int cherryPickup(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    for (int row = m - 1; row >= 0; row--) {
      vector<vector<int>> temp(n, vector<int>(n, -1));
      for (int col1 = 0; col1 < n; col1++) {
        for (int col2 = 0; col2 < n; col2++) {
          if (row == m - 1) {
            if (col1 == col2)
              temp[col1][col2] = grid[row][col1];
            else
              temp[col1][col2] = grid[row][col1] + grid[row][col2];
          } else {
            vector<int> move = {-1, 0, 1};
            int ans = INT_MIN;
            for (auto it1 : move) {
              for (auto it2 : move) {
                int value;
                if (col1 == col2)
                  value = grid[row][col1];
                else
                  value = grid[row][col1] + grid[row][col2];
                if (col1 + it1 >= 0 && col1 + it1 <= n - 1 && col2 + it2 >= 0 &&
                    col2 + it2 <= n - 1)
                  value += dp[col1 + it1][col2 + it2];
                else
                  value = INT_MIN;
                ans = max(ans, value);
              }
            }
            temp[col1][col2] = ans;
          }
        }
      }
      dp = temp;
    }
    return dp[0][n - 1];
  }
};
