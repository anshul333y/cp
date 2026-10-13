#include <bits/stdc++.h>
using namespace std;

// ── Target Sum ───────────────────────────────────────────────
// same as dp-18

// 1. Recursion                  |  T: O(2^n)  S: O(n)
class Recursion {
private:
  int rec(int idx, int target, vector<int> &nums) {
    if (idx == 0) {
      if (target == 0 && nums[0] == 0)
        return 2;
      else if (target == 0 || target == nums[0])
        return 1;
      else
        return 0;
    }

    int plus = 0;
    if (nums[idx] <= target)
      plus = rec(idx - 1, target - nums[idx], nums);
    int minus = rec(idx - 1, target, nums);

    return plus + minus;
  }

public:
  int findTargetSumWays(vector<int> &nums, int target) {
    int n = nums.size();

    int sum = 0;
    for (auto it : nums)
      sum += it;

    if (target > sum || (sum + target) % 2 != 0)
      return 0;
    else
      return rec(n - 1, (sum + target) / 2, nums);
  }
};

// 2. Memoization (top-down DP)  |  T: O(n)    S: O(n)
class Memoization {};

// 3. Tabulation (bottom-up DP)  |  T: O(n)    S: O(n)
class Tabulation {};

// 4. Space Optimized            |  T: O(n)    S: O(1)
class SpaceOptimized {};
