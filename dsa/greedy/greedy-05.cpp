#include <bits/stdc++.h>
using namespace std;

// ── Jump Game II ─────────────────────────────────────────────

// T: O(nums[idx]^n) exponential  S: O(n) recursion stack
class brute {
private:
  int rec(vector<int> &nums, int idx, int jump) {
    if (idx >= nums.size() - 1) {
      return jump;
    }

    int ans = INT_MAX;
    for (int i = 1; i <= nums[idx]; i++) {
      ans = min(ans, rec(nums, idx + i, jump + 1));
    }

    return ans;
  }

public:
  int jump(vector<int> &nums) { return rec(nums, 0, 0); }
};

// T: O(n^2) S: O(n^2)
class better {
private:
  int rec(vector<int> &nums, int idx, int jump, vector<vector<int>> &dp) {
    if (idx >= nums.size() - 1) {
      return jump;
    }

    if (dp[idx][jump] != -1) {
      return dp[idx][jump];
    }

    int ans = INT_MAX;
    for (int i = 1; i <= nums[idx]; i++) {
      ans = min(ans, rec(nums, idx + i, jump + 1, dp));
    }

    return dp[idx][jump] = ans;
  }

public:
  int jump(vector<int> &nums) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));

    return rec(nums, 0, 0, dp);
  }
};

// T: O(n) S: O(1)
class optimal {
public:
  int jump(vector<int> &nums) {
    int n = nums.size();
    int l = 0, r = 0;

    int ans = 0;
    while (r < n - 1) {
      int maxRange = 0;

      for (int i = l; i <= r; i++) {
        maxRange = max(maxRange, i + nums[i]);
      }

      ans++;
      l = r + 1;
      r = maxRange;
    }

    return ans;
  }
};
