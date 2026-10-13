#include <bits/stdc++.h>
using namespace std;

// ── Best Time to Buy and Sell Stock with Cooldown ─────────────

// 1. Recursion                  |  T: O(2^n)  S: O(n)
class Recursion {};

// 2. Memoization (top-down DP)  |  T: O(n)    S: O(n)
class Memoization {};

// 3. Tabulation (bottom-up DP)  |  T: O(n)    S: O(n)
class Tabulation {
public:
  int maxProfit(vector<int> &prices) {
    int n = prices.size();
    vector<vector<int>> dp(n + 2, vector<int>(2, 0));
    dp[n][0] = 0, dp[n][1] = 0;
    for (int idx = n - 1; idx >= 0; idx--) {
      for (int buy = 0; buy < 2; buy++) {
        int profit;
        if (buy) {
          profit = max(-prices[idx] + dp[idx + 1][0], dp[idx + 1][1]);
        } else {
          profit = max(prices[idx] + dp[idx + 2][1], dp[idx + 1][0]);
        }
        dp[idx][buy] = profit;
      }
    }
    return dp[0][1];
  }
};

// 4. Space Optimized            |  T: O(n)    S: O(1)
class SpaceOptimized {};
