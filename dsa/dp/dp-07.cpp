#include <bits/stdc++.h>
using namespace std;

// ── Ninja's Training ─────────────────────────────────────────

// 1. Memoization (top-down DP)  |  T: O(n)  S: O(n)
class Memoization {
private:
  int rec(int idx, vector<vector<int>> &points, vector<vector<int>> &dp,
          int taken) {
    if (idx < 0)
      return 0;
    if (dp[idx][taken] != -1)
      return dp[idx][taken];
    int ans = INT_MIN;
    for (int j = 0; j <= 2; j++) {
      if (j != taken) {
        int curr = points[idx][j] + rec(idx - 1, points, dp, j);
        ans = max(ans, curr);
      }
    }
    return dp[idx][taken] = ans;
  }

public:
  int maximumPoints(vector<vector<int>> &mat) {
    int n = mat.size();
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return rec(n - 1, mat, dp, 3);
  }
};

// 2. Tabulation (bottom-up DP)  |  T: O(n)  S: O(n)
class Tabulation {
public:
  int maximumPoints(vector<vector<int>> &mat) {
    int n = mat.size();
    vector<vector<int>> dp(n, vector<int>(4, -1));
    for (int i = 0; i <= n - 1; i++) {
      for (int taken = 0; taken <= 3; taken++) {
        int ans = INT_MIN;
        for (int j = 0; j <= 2; j++) {
          if (j != taken) {
            if (i == 0)
              ans = max(ans, mat[i][j]);
            else
              ans = max(ans, mat[i][j] + dp[i - 1][j]);
          }
        }
        dp[i][taken] = ans;
      }
    }
    return dp[n - 1][3];
  }
};

// 3. Space Optimized            |  T: O(n)  S: O(1)
class SpaceOptimized {
public:
  int maximumPoints(vector<vector<int>> &mat) {
    int n = mat.size();
    vector<int> dp(4, -1);
    for (int i = 0; i <= n - 1; i++) {
      vector<int> temp(4, -1);
      for (int taken = 0; taken <= 3; taken++) {
        for (int j = 0; j <= 2; j++) {
          if (j != taken) {
            if (i == 0)
              dp[taken] = max(dp[taken], mat[i][j]);
            else
              temp[taken] = max(temp[taken], mat[i][j] + dp[j]);
          }
        }
      }
      if (i != 0)
        dp = temp;
    }
    return dp[3];
  }
};
