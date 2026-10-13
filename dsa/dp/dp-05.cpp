#include <bits/stdc++.h>
using namespace std;

// ── House Robber ─────────────────────────────────────────────

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

public:
  int rob(vector<int> &nums) {
    int size = nums.size();
    vector<int> dp(size, -1);
    return rec(size - 1, nums, dp);
  }
};

// 2. Tabulation (bottom-up DP)  |  T: O(n)  S: O(n)
class Tabulation {
public:
  int rob(vector<int> &nums) {
    int size = nums.size();
    if (size == 1)
      return nums[0];
    vector<int> dp(size, -1);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for (int i = 2; i <= size - 1; i++) {
      int take = nums[i] + dp[i - 2];
      int notTake = dp[i - 1];
      dp[i] = max(take, notTake);
    }
    return dp[size - 1];
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
    for (int i = 2; i <= n; i++) {
      int take = nums[i] + prev2;
      int notTake = prev1;
      int curr = max(take, notTake);
      prev2 = prev1;
      prev1 = curr;
    }
    return prev1;
  }
};
