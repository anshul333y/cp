#include <bits/stdc++.h>
using namespace std;

// ── Subset Sum ───────────────────────────────────────────────

// 1. Memoization (top-down DP)  |  T: O(n*sum)  S: O(n*sum)
class Memoization {
private:
  bool rec(int idx, int sum, vector<int> &arr, vector<vector<int>> &dp) {
    if (sum == 0)
      return true;
    if (idx == 0)
      return arr[0] == sum;
    if (dp[idx][sum] != -1)
      return dp[idx][sum];
    int take = false, notTake = false;
    if (sum >= arr[idx])
      take = rec(idx - 1, sum - arr[idx], arr, dp);
    notTake = rec(idx - 1, sum, arr, dp);
    return dp[idx][sum] = take || notTake;
  }

public:
  bool isSubsetSum(vector<int> &arr, int sum) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
    return rec(n - 1, sum, arr, dp);
  }
};

// 2. Tabulation (bottom-up DP)  |  T: O(n*sum)  S: O(n*sum)
class Tabulation {
public:
  bool isSubsetSum(vector<int> &arr, int sum) {
    int n = arr.size();
    vector<vector<bool>> dp(n, vector<bool>(sum + 1, 0));
    for (int idx = 0; idx < n; idx++) {
      for (int target = 0; target < sum + 1; target++) {
        if (target == 0)
          dp[idx][target] = true;
        if (idx == 0)
          dp[idx][arr[0]] = true;
        else {
          int take = false, notTake = false;
          if (target >= arr[idx])
            take = dp[idx - 1][target - arr[idx]];
          notTake = dp[idx - 1][target];
          dp[idx][target] = take || notTake;
        }
      }
    }
    return dp[n - 1][sum];
  }
};

// 3. Space Optimized            |  T: O(n*sum)  S: O(sum)
class SpaceOptimized {
public:
  bool isSubsetSum(vector<int> &arr, int sum) {
    int n = arr.size();
    vector<bool> dp(sum + 1, 0);
    for (int idx = 0; idx < n; idx++) {
      vector<bool> temp(sum + 1, 0);
      for (int target = 0; target < sum + 1; target++) {
        if (target == 0)
          temp[target] = true;
        if (idx == 0)
          temp[arr[0]] = true;
        else {
          int take = false, notTake = false;
          if (target >= arr[idx])
            take = dp[target - arr[idx]];
          notTake = dp[target];
          temp[target] = take || notTake;
        }
      }
      dp = temp;
    }
    return dp[sum];
  }
};
