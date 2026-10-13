#include <bits/stdc++.h>
using namespace std;

// ── Climbing Stairs ──────────────────────────────────────────

// 1. Memoization (top-down DP)  |  T: O(n)  S: O(n)
class Memoization {
private:
  int solve(int n, vector<int> &dp) {
    if (n <= 2)
      return n;
    if (dp[n] != -1)
      return dp[n];
    return dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
  }

public:
  int climbStairs(int n) {
    vector<int> dp(n + 1, -1);
    return solve(n, dp);
  }
};

// 2. Tabulation (bottom-up DP)  |  T: O(n)  S: O(n)
class Tabulation {
public:
  int climbStairs(int n) {
    if (n <= 2)
      return n;
    vector<int> dp(n + 1);
    dp[1] = 1, dp[2] = 2;
    for (int i = 3; i <= n; i++)
      dp[i] = dp[i - 2] + dp[i - 1];
    return dp[n];
  }
};

// 3. Space Optimized            |  T: O(n)  S: O(1)
class SpaceOptimized {
public:
  int climbStairs(int n) {
    if (n <= 2)
      return n;
    int prev2 = 1, prev1 = 2, curr;
    for (int i = 3; i <= n; i++) {
      curr = prev2 + prev1;
      prev2 = prev1;
      prev1 = curr;
    }
    return curr;
  }
};
