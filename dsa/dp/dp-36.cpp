#include <bits/stdc++.h>
using namespace std;

// ── Best Time to Buy and Sell Stock II ────────────────────────

// 1. Recursion                  |  T: O(2^n)  S: O(n)
class Recursion {
private:
  int fun(int idx, int buy, vector<int> &prices) {
    if (idx == prices.size())
      return 0;
    int profit;
    if (buy) {
      profit =
          max(-prices[idx] + fun(idx + 1, 0, prices), fun(idx + 1, 1, prices));
    } else {
      profit =
          max(prices[idx] + fun(idx + 1, 1, prices), fun(idx + 1, 0, prices));
    }
    return profit;
  }

public:
  int maxProfit(vector<int> &prices) {
    int n = prices.size();
    return fun(0, 1, prices);
  }
};

// 2. Memoization (top-down DP)  |  T: O(n)    S: O(n)
class Memoization {
private:
  int fun(int idx, int buy, vector<int> &prices, vector<vector<int>> &dp) {
    if (idx == prices.size())
      return 0;
    if (dp[idx][buy] != -1)
      return dp[idx][buy];
    int profit;
    if (buy) {
      profit = max(-prices[idx] + fun(idx + 1, 0, prices, dp),
                   fun(idx + 1, 1, prices, dp));
    } else {
      profit = max(prices[idx] + fun(idx + 1, 1, prices, dp),
                   fun(idx + 1, 0, prices, dp));
    }
    return dp[idx][buy] = profit;
  }

public:
  int maxProfit(vector<int> &prices) {
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    return fun(0, 1, prices, dp);
  }
};

// 3. Tabulation (bottom-up DP)  |  T: O(n)    S: O(n)
class Tabulation {
public:
  int maxProfit(vector<int> &prices) {
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    dp[n][0] = 0, dp[n][1] = 0;
    for (int idx = n - 1; idx >= 0; idx--) {
      for (int buy = 0; buy < 2; buy++) {
        int profit;
        if (buy) {
          profit = max(-prices[idx] + dp[idx + 1][0], dp[idx + 1][1]);
        } else {
          profit = max(prices[idx] + dp[idx + 1][1], dp[idx + 1][0]);
        }
        dp[idx][buy] = profit;
      }
    }
    return dp[0][1];
  }
};

// 4. Space Optimized            |  T: O(n)    S: O(1)
class SpaceOptimized {
public:
  int maxProfit(vector<int> &prices) {
    int n = prices.size();
    vector<int> curr(2, 0), prev(2, 0);
    prev[0] = 0, prev[1] = 0;
    for (int idx = n - 1; idx >= 0; idx--) {
      for (int buy = 0; buy < 2; buy++) {
        int profit;
        if (buy) {
          profit = max(-prices[idx] + prev[0], prev[1]);
        } else {
          profit = max(prices[idx] + prev[1], prev[0]);
        }
        curr[buy] = profit;
      }
      prev = curr;
    }
    return prev[1];
  }
};
