#include <bits/stdc++.h>
using namespace std;

// ── House Robber II ──────────────────────────────────────────

// 1. Memoization (top-down DP)  |  T: O(n)  S: O(n)
class Memoization {
private:
  int rec(int idx, vector<int> &nums, vector<int> &dp) {
    if (idx < 0)
      return 0;
    if (dp[idx] != -1)
      return dp[idx];
    int take = nums[idx] + rec(idx - 2, nums, dp);
    int notTake = rec(idx - 1, nums, dp);
    return dp[idx] = max(take, notTake);
  }
  int rec2(int idx, vector<int> &nums, vector<int> &dp) {
    if (idx <= 0)
      return 0;
    if (dp[idx] != -1)
      return dp[idx];
    int take = nums[idx] + rec2(idx - 2, nums, dp);
    int notTake = rec2(idx - 1, nums, dp);
    return dp[idx] = max(take, notTake);
  }

public:
  int rob(vector<int> &nums) {
    int n = nums.size() - 1;
    if (n == 0)
      return nums[n];
    vector<int> dp(n + 1, -1);
    int last = rec(n - 1, nums, dp);
    dp.assign(n + 1, -1);
    int first = rec2(n, nums, dp);
    return max(first, last);
  }
};

// 2. Tabulation (bottom-up DP)  |  T: O(n)  S: O(n)
class Tabulation {
public:
  int rob(vector<int> &nums) {
    int n = nums.size();
    if (n == 1)
      return nums[0];
    vector<int> dp(n, -1);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for (int i = 2; i < n - 1; i++) {
      int take = nums[i] + dp[i - 2];
      int notTake = dp[i - 1];
      dp[i] = max(take, notTake);
    }
    int last = dp[n - 2];
    dp.assign(n, -1);
    dp[0] = 0;
    dp[1] = nums[1];
    for (int i = 2; i <= n - 1; i++) {
      int take = nums[i] + dp[i - 2];
      int notTake = dp[i - 1];
      dp[i] = max(take, notTake);
    }
    int first = dp[n - 1];
    return max(first, last);
  }
};

// 3. Space Optimized            |  T: O(n)  S: O(1)
class SpaceOptimized {
public:
  int rob(vector<int> &nums) {
    int n = nums.size() - 1;
    if (n == 0)
      return nums[0];
    int prev2 = nums[0], prev1 = max(nums[0], nums[1]);
    for (int i = 2; i < n; i++) {
      int take = nums[i] + prev2;
      int notTake = prev1;
      int curr = max(take, notTake);
      prev2 = prev1;
      prev1 = curr;
    }
    int last = prev1;
    prev2 = 0, prev1 = nums[1];
    for (int i = 2; i <= n; i++) {
      int take = nums[i] + prev2;
      int notTake = prev1;
      int curr = max(take, notTake);
      prev2 = prev1;
      prev1 = curr;
    }
    int first = prev1;
    return max(first, last);
  }
};
