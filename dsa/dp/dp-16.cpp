#include <bits/stdc++.h>
using namespace std;

// ── Minimum Subset Sum Difference ────────────────────────────

// 1. Recursion                  |  T: O(2^n)    S: O(n)
class Recursion {};

// 2. Memoization (top-down DP)  |  T: O(n*sum)  S: O(n*sum)
class Memoization {};

// 3. Tabulation (bottom-up DP)  |  T: O(n*sum)  S: O(n*sum)
class Tabulation {
public:
  int minDifference(vector<int> &arr) {
    int n = arr.size();
    int sum = 0;
    for (auto it : arr)
      sum += it;
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
    int ans = INT_MAX;
    for (int i = 0; i < sum + 1; i++) {
      if (dp[n - 1][i])
        ans = min(ans, abs(sum - i - i));
    }
    return ans;
  }
};

// 4. Space Optimized            |  T: O(n*sum)  S: O(sum)
class SpaceOptimized {
public:
  int minDifference(vector<int> &arr) {
    int n = arr.size();
    int sum = 0;
    for (auto it : arr)
      sum += it;
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
    int ans = INT_MAX;
    for (int i = 0; i < sum + 1; i++) {
      if (dp[i])
        ans = min(ans, abs(sum - i - i));
    }
    return ans;
  }
};
