#include <bits/stdc++.h>
using namespace std;

// ── Perfect Sum (Count Subsets with Sum K) ───────────────────

// 1. Recursion                  |  T: O(2^n)  S: O(n)
class Recursion {
private:
  int rec(vector<int> &arr, int target, int idx) {
    if (idx == 0) {
      if (target == 0 && arr[0] == 0)
        return 2;
      if (target == 0 || target == arr[0])
        return 1;
      return 0;
    }
    int take = 0;
    if (arr[idx] <= target)
      take = rec(arr, target - arr[idx], idx - 1);
    int notTake = rec(arr, target, idx - 1);
    return take + notTake;
  }

public:
  int perfectSum(vector<int> &arr, int k) {
    int n = arr.size();
    return rec(arr, k, n - 1);
  }
};

// 2. Memoization (top-down DP)  |  T: O(n*k)  S: O(n*k)
class Memoization {
private:
  int rec(vector<int> &arr, int target, int idx, vector<vector<int>> &dp) {
    if (idx == 0) {
      if (target == 0 && arr[0] == 0)
        return 2;
      if (target == 0 || target == arr[0])
        return 1;
      return 0;
    }
    if (dp[idx][target] != -1)
      return dp[idx][target];
    int take = 0;
    if (arr[idx] <= target)
      take = rec(arr, target - arr[idx], idx - 1, dp);
    int notTake = rec(arr, target, idx - 1, dp);
    return dp[idx][target] = take + notTake;
  }

public:
  int perfectSum(vector<int> &arr, int k) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return rec(arr, k, n - 1, dp);
  }
};

// 3. Tabulation (bottom-up DP)  |  T: O(n*k)  S: O(n*k)
class Tabulation {
public:
  int perfectSum(vector<int> &arr, int k) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, 0));
    for (int idx = 0; idx < n; idx++) {
      for (int target = 0; target < k + 1; target++) {
        if (idx == 0) {
          if (target == 0 && arr[0] == 0)
            dp[idx][target] = 2;
          else if (target == 0 || target == arr[0])
            dp[idx][target] = 1;
        } else {
          int take = 0;
          if (arr[idx] <= target)
            take = dp[idx - 1][target - arr[idx]];
          int notTake = dp[idx - 1][target];
          dp[idx][target] = take + notTake;
        }
      }
    }
    return dp[n - 1][k];
  }
};

// 4. Space Optimized            |  T: O(n*k)  S: O(k)
class SpaceOptimized {
public:
  int perfectSum(vector<int> &arr, int k) {
    int n = arr.size();
    vector<int> dp(k + 1, 0);
    for (int idx = 0; idx < n; idx++) {
      vector<int> curr(k + 1, 0);
      for (int target = 0; target < k + 1; target++) {
        if (idx == 0) {
          if (target == 0 && arr[0] == 0)
            curr[target] = 2;
          else if (target == 0 || target == arr[0])
            curr[target] = 1;
        } else {
          int take = 0;
          if (arr[idx] <= target)
            take = dp[target - arr[idx]];
          int notTake = dp[target];
          curr[target] = take + notTake;
        }
      }
      dp = curr;
    }
    return dp[k];
  }
};
