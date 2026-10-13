#include <bits/stdc++.h>
using namespace std;

// ── Frog Jump ────────────────────────────────────────────────

// 1. Memoization (top-down DP)  |  T: O(n)  S: O(n)
class Memoization {
private:
  int rec(int idx, vector<int> &height, vector<int> &dp) {
    if (idx == 0)
      return 0;
    if (idx == 1)
      return abs(height[idx] - height[idx - 1]);
    if (dp[idx] != -1)
      return dp[idx];
    int one = abs(height[idx] - height[idx - 1]) + rec(idx - 1, height, dp);
    int two = abs(height[idx] - height[idx - 2]) + rec(idx - 2, height, dp);
    return dp[idx] = min(one, two);
  }

public:
  int minCost(vector<int> &height) {
    int size = height.size();
    vector<int> dp(size, -1);
    return rec(size - 1, height, dp);
  }
};

// 2. Tabulation (bottom-up DP)  |  T: O(n)  S: O(n)
class Tabulation {
public:
  int minCost(vector<int> &height) {
    int size = height.size();
    if (size - 1 == 0)
      return 0;
    if (size - 1 == 1)
      return abs(height[1] - height[0]);
    vector<int> dp(size);
    dp[0] = 0, dp[1] = abs(height[1] - height[0]);
    for (int i = 2; i <= size - 1; i++) {
      int one = abs(height[i] - height[i - 1]) + dp[i - 1];
      int two = abs(height[i] - height[i - 2]) + dp[i - 2];
      dp[i] = min(one, two);
    }
    return dp[size - 1];
  }
};

// 3. Space Optimized            |  T: O(n)  S: O(1)
class SpaceOptimized {
public:
  int minCost(vector<int> &height) {
    int size = height.size();
    if (size - 1 == 0)
      return 0;
    if (size - 1 == 1)
      return abs(height[1] - height[0]);
    int prev2 = 0, prev1 = abs(height[1] - height[0]), curr;
    for (int i = 2; i <= size - 1; i++) {
      int oneStep = abs(height[i] - height[i - 1]) + prev1;
      int twoStep = abs(height[i] - height[i - 2]) + prev2;
      curr = min(oneStep, twoStep);
      prev2 = prev1;
      prev1 = curr;
    }
    return curr;
  }
};
