#include <bits/stdc++.h>
using namespace std;

// ── Partition Equal Subset Sum ───────────────────────────────

// 1. Memoization (top-down DP)  |  T: O(n*sum)  S: O(n*sum)
class Memoization {
private:
  bool rec(int idx, int sum, vector<int> &nums, vector<vector<int>> &dp) {
    if (sum == 0)
      return true;
    if (idx == 0)
      return sum == nums[0];
    if (dp[idx][sum] != -1)
      return dp[idx][sum];
    bool take = false, notTake = false;
    notTake = rec(idx - 1, sum, nums, dp);
    if (sum >= nums[idx])
      take = rec(idx - 1, sum - nums[idx], nums, dp);
    return dp[idx][sum] = take || notTake;
  }

public:
  bool canPartition(vector<int> &nums) {
    int n = nums.size();
    if (n == 1)
      return false;
    int sum = 0;
    for (auto it : nums)
      sum += it;
    if (sum % 2 == 0) {
      vector<vector<int>> dp(n, vector<int>(sum / 2 + 1, -1));
      return rec(n - 1, sum / 2, nums, dp);
    } else
      return false;
  }
};

// 2. Tabulation (bottom-up DP)  |  T: O(n*sum)  S: O(n*sum)
class Tabulation {
public:
  bool canPartition(vector<int> &nums) {
    int n = nums.size();
    if (n == 1)
      return false;
    int sum = 0;
    for (auto it : nums)
      sum += it;
    if (sum % 2 == 0) {
      vector<vector<bool>> dp(n, vector<bool>(sum / 2 + 1, false));
      for (int idx = 0; idx < n; idx++) {
        for (int target = 0; target < sum / 2 + 1; target++) {
          if (target == 0)
            dp[idx][target] = true;
          if (idx == 0) {
            if (nums[0] <= sum / 2)
              dp[idx][nums[0]] = true;
          } else {
            bool take = false, notTake = false;
            notTake = dp[idx - 1][target];
            if (target >= nums[idx])
              take = dp[idx - 1][target - nums[idx]];
            dp[idx][target] = take || notTake;
          }
        }
      }
      return dp[n - 1][sum / 2];
    } else
      return false;
  }
};

// 3. Space Optimized            |  T: O(n*sum)  S: O(sum)
class SpaceOptimized {
public:
  bool canPartition(vector<int> &nums) {
    int n = nums.size();
    if (n == 1)
      return false;
    int sum = 0;
    for (auto it : nums)
      sum += it;
    if (sum % 2 == 0) {
      vector<bool> dp(sum / 2 + 1, false);
      for (int idx = 0; idx < n; idx++) {
        vector<bool> temp(sum / 2 + 1, false);
        for (int target = 0; target < sum / 2 + 1; target++) {
          if (target == 0)
            temp[target] = true;
          if (idx == 0) {
            if (nums[0] <= sum / 2)
              temp[nums[0]] = true;
          } else {
            bool take = false, notTake = false;
            notTake = dp[target];
            if (target >= nums[idx])
              take = dp[target - nums[idx]];
            temp[target] = take || notTake;
          }
        }
        dp = temp;
      }
      return dp[sum / 2];
    } else
      return false;
  }
};
