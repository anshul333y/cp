#include <bits/stdc++.h>
using namespace std;

// ── 0/1 Knapsack ─────────────────────────────────────────────

// 1. Recursion                  |  T: O(2^n)  S: O(n)
class Recursion {
private:
  int rec(int idx, int w, vector<int> &wt, vector<int> &val) {
    if (idx == 0) {
      if (w >= wt[0])
        return val[0];
      else
        return 0;
    }
    int take = 0;
    if (w >= wt[idx])
      take = val[idx] + rec(idx - 1, w - wt[idx], wt, val);
    int notTake = rec(idx - 1, w, wt, val);
    return max(take, notTake);
  }

public:
  int knapsack(int W, vector<int> &val, vector<int> &wt) {
    int n = val.size();
    return rec(n - 1, W, wt, val);
  }
};

// 2. Memoization (top-down DP)  |  T: O(n*W)  S: O(n*W)
class Memoization {
private:
  int rec(int idx, int w, vector<int> &wt, vector<int> &val,
          vector<vector<int>> &dp) {
    if (idx == 0) {
      if (w >= wt[0])
        return val[0];
      else
        return 0;
    }
    if (dp[idx][w] != -1)
      return dp[idx][w];
    int take = 0;
    if (w >= wt[idx])
      take = val[idx] + rec(idx - 1, w - wt[idx], wt, val, dp);
    int notTake = rec(idx - 1, w, wt, val, dp);
    return dp[idx][w] = max(take, notTake);
  }

public:
  int knapsack(int W, vector<int> &val, vector<int> &wt) {
    int n = val.size();
    vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    return rec(n - 1, W, wt, val, dp);
  }
};

// 3. Tabulation (bottom-up DP)  |  T: O(n*W)  S: O(n*W)
class Tabulation {
public:
  int knapsack(int W, vector<int> &val, vector<int> &wt) {
    int n = val.size();
    vector<vector<int>> dp(n, vector<int>(W + 1, 0));
    for (int idx = 0; idx < n; idx++) {
      for (int w = 0; w < W + 1; w++) {
        if (idx == 0) {
          if (w >= wt[0])
            dp[idx][w] = val[0];
          else
            dp[idx][w] = 0;
        } else {
          int take = 0;
          if (w >= wt[idx])
            take = val[idx] + dp[idx - 1][w - wt[idx]];
          int notTake = dp[idx - 1][w];
          dp[idx][w] = max(take, notTake);
        }
      }
    }
    return dp[n - 1][W];
  }
};

// 4. Space Optimized            |  T: O(n*W)  S: O(W)
class SpaceOptimized {
public:
  int knapsack(int W, vector<int> &val, vector<int> &wt) {
    int n = val.size();
    vector<int> dp(W + 1, 0);
    for (int idx = 0; idx < n; idx++) {
      for (int w = W; w >= 0; w--) {
        if (idx == 0) {
          if (w >= wt[0])
            dp[w] = val[0];
          else
            dp[w] = 0;
        } else {
          int take = 0;
          if (w >= wt[idx])
            take = val[idx] + dp[w - wt[idx]];
          int notTake = dp[w];
          dp[w] = max(take, notTake);
        }
      }
    }
    return dp[W];
  }
};
