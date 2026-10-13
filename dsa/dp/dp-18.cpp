#include <bits/stdc++.h>
using namespace std;

// ── Partitions with Given Difference ─────────────────────────

// 1. Recursion                  |  T: O(2^n)  S: O(n)
class Recursion {
private:
  int rec(int idx, int sum, vector<int> &arr) {
    if (idx == 0) {
      if (sum == 0 && arr[0] == 0)
        return 2;
      if (sum == 0 || sum == arr[0])
        return 1;
      return 0;
    }
    int take = 0;
    if (arr[idx] <= sum)
      take = rec(idx - 1, sum - arr[idx], arr);
    int notTake = rec(idx - 1, sum, arr);
    return take + notTake;
  }

public:
  int countPartitions(vector<int> &arr, int diff) {
    int sum = 0;
    for (auto it : arr)
      sum += it;
    if (diff > sum || (sum + diff) % 2 == 1)
      return 0;
    int n = arr.size();
    int s1 = (sum + diff) / 2;
    return rec(n - 1, s1, arr);
  }
};

// 2. Memoization (top-down DP)  |  T: O(n*sum)  S: O(n*sum)
class Memoization {
private:
  int rec(int idx, int sum, vector<int> &arr, vector<vector<int>> &dp) {
    if (idx == 0) {
      if (sum == 0 && arr[0] == 0)
        return 2;
      if (sum == 0 || sum == arr[0])
        return 1;
      return 0;
    }
    if (dp[idx][sum] != -1)
      return dp[idx][sum];
    int take = 0;
    if (arr[idx] <= sum)
      take = rec(idx - 1, sum - arr[idx], arr, dp);
    int notTake = rec(idx - 1, sum, arr, dp);
    return dp[idx][sum] = take + notTake;
  }

public:
  int countPartitions(vector<int> &arr, int diff) {
    int sum = 0;
    for (auto it : arr)
      sum += it;
    if (diff > sum || (sum + diff) % 2 == 1)
      return 0;
    int n = arr.size();
    int s1 = (sum + diff) / 2;
    vector<vector<int>> dp(n, vector<int>(s1 + 1, -1));
    return rec(n - 1, s1, arr, dp);
  }
};

// 3. Tabulation (bottom-up DP)  |  T: O(n*sum)  S: O(n*sum)
class Tabulation {
public:
  int countPartitions(vector<int> &arr, int diff) {
    int sum = 0;
    for (auto it : arr)
      sum += it;
    if (diff > sum || (sum + diff) % 2 == 1)
      return 0;
    int n = arr.size();
    int s1 = (sum + diff) / 2;
    vector<vector<int>> dp(n, vector<int>(s1 + 1, 0));
    for (int idx = 0; idx < n; idx++) {
      for (int target = 0; target < s1 + 1; target++) {
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
    return dp[n - 1][s1];
  }
};

// 4. Space Optimized            |  T: O(n*sum)  S: O(sum)
class SpaceOptimized {
public:
  int countPartitions(vector<int> &arr, int diff) {
    int sum = 0;
    for (auto it : arr)
      sum += it;
    if (diff > sum || (sum + diff) % 2 == 1)
      return 0;
    int n = arr.size();
    int s1 = (sum + diff) / 2;
    vector<int> dp(s1 + 1, 0);
    for (int idx = 0; idx < n; idx++) {
      vector<int> curr(s1 + 1, 0);
      for (int target = 0; target < s1 + 1; target++) {
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
    return dp[s1];
  }
};
