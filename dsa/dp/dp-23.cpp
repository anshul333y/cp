#include <bits/stdc++.h>
using namespace std;

// ── Unbounded Knapsack ───────────────────────────────────────

// 1. Recursion                  |  T: O(2^capacity)  S: O(capacity)
class Recursion {
private:
  int rec(int idx, int w, vector<int> &wt, vector<int> &val) {
    if (idx == 0) {
      return (w / wt[0]) * val[0];
    }
    int take = 0;
    if (w >= wt[idx])
      take = val[idx] + rec(idx, w - wt[idx], wt, val);
    int notTake = rec(idx - 1, w, wt, val);
    return max(take, notTake);
  }

public:
  int knapSack(vector<int> &val, vector<int> &wt, int capacity) {
    int n = val.size();
    return rec(n - 1, capacity, wt, val);
  }
};

// 2. Memoization (top-down DP)  |  T: O(n*capacity)  S: O(n*capacity)
class Memoization {
private:
  int rec(int idx, int w, vector<int> &wt, vector<int> &val,
          vector<vector<int>> &dp) {
    if (idx == 0) {
      return (w / wt[0]) * val[0];
    }
    if (dp[idx][w] != -1)
      return dp[idx][w];
    int take = 0;
    if (w >= wt[idx])
      take = val[idx] + rec(idx, w - wt[idx], wt, val, dp);
    int notTake = rec(idx - 1, w, wt, val, dp);
    return dp[idx][w] = max(take, notTake);
  }

public:
  int knapSack(vector<int> &val, vector<int> &wt, int capacity) {
    int n = val.size();
    vector<vector<int>> dp(n, vector<int>(capacity + 1, -1));
    return rec(n - 1, capacity, wt, val, dp);
  }
};

// 3. Tabulation (bottom-up DP)  |  T: O(n*capacity)  S: O(n*capacity)
class Tabulation {
public:
  int knapSack(vector<int> &val, vector<int> &wt, int capacity) {
    int n = val.size();
    vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));
    for (int idx = 0; idx < n; idx++) {
      for (int w = 0; w < capacity + 1; w++) {
        if (idx == 0) {
          dp[idx][w] = (w / wt[0]) * val[0];
        } else {
          int take = 0;
          if (w >= wt[idx])
            take = val[idx] + dp[idx][w - wt[idx]];
          int notTake = dp[idx - 1][w];
          dp[idx][w] = max(take, notTake);
        }
      }
    }
    return dp[n - 1][capacity];
  }
};

// 4. Space Optimized            |  T: O(n*capacity)  S: O(capacity)
class SpaceOptimized {
public:
  int knapSack(vector<int> &val, vector<int> &wt, int capacity) {
    int n = val.size();
    vector<int> dp(capacity + 1, 0);
    for (int idx = 0; idx < n; idx++) {
      for (int w = 0; w < capacity + 1; w++) {
        if (idx == 0) {
          dp[w] = (w / wt[0]) * val[0];
        } else {
          int take = 0;
          if (w >= wt[idx])
            take = val[idx] + dp[w - wt[idx]];
          int notTake = dp[w];
          dp[w] = max(take, notTake);
        }
      }
    }
    return dp[capacity];
  }
};
