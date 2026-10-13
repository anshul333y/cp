#include <bits/stdc++.h>
using namespace std;

// ── Best Time to Buy and Sell Stock III ───────────────────────

// 1. Recursion                  |  T: O(2^n)  S: O(n)
class Recursion {
private:
  int fun(int idx, int buy, vector<int> &prices, int trans) {
    if (idx == prices.size())
      return 0;
    if (trans == 0)
      return 0;
    int profit;
    if (buy) {
      profit = max(-prices[idx] + fun(idx + 1, 0, prices, trans),
                   fun(idx + 1, 1, prices, trans));
    } else {
      profit = max(prices[idx] + fun(idx + 1, 1, prices, trans - 1),
                   fun(idx + 1, 0, prices, trans));
    }
    return profit;
  }

public:
  int maxProfit(vector<int> &prices) {
    int n = prices.size();
    return fun(0, 1, prices, 2);
  }
};

// 2. Memoization (top-down DP)  |  T: O(n)    S: O(n)
class Memoization {
private:
  int fun(int idx, int buy, vector<int> &prices,
          vector<vector<vector<int>>> &dp, int trans) {
    if (idx == prices.size())
      return 0;
    if (trans == 0)
      return 0;
    if (dp[idx][buy][trans] != -1)
      return dp[idx][buy][trans];
    int profit;
    if (buy) {
      profit = max(-prices[idx] + fun(idx + 1, 0, prices, dp, trans),
                   fun(idx + 1, 1, prices, dp, trans));
    } else {
      profit = max(prices[idx] + fun(idx + 1, 1, prices, dp, trans - 1),
                   fun(idx + 1, 0, prices, dp, trans));
    }
    return dp[idx][buy][trans] = profit;
  }

public:
  int maxProfit(vector<int> &prices) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(n,
                                   vector<vector<int>>(2, vector<int>(3, -1)));
    return fun(0, 1, prices, dp, 2);
  }
};

// 3. Tabulation (bottom-up DP)  |  T: O(n)    S: O(n)
class Tabulation {
public:
  int maxProfit(vector<int> &prices) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(n + 1,
                                   vector<vector<int>>(2, vector<int>(3, 0)));
    for (int idx = 0; idx < n + 1; idx++) {
      for (int buy = 0; buy < 2; buy++) {
        dp[idx][buy][0] = 0;
      }
    }
    for (int buy = 0; buy < 2; buy++) {
      for (int trans = 0; trans < 3; trans++) {
        dp[n][buy][trans] = 0;
      }
    }
    for (int idx = n - 1; idx >= 0; idx--) {
      for (int buy = 0; buy < 2; buy++) {
        for (int trans = 1; trans < 3; trans++) {
          int profit;
          if (buy) {
            profit = max(-prices[idx] + dp[idx + 1][0][trans],
                         dp[idx + 1][1][trans]);
          } else {
            profit = max(prices[idx] + dp[idx + 1][1][trans - 1],
                         dp[idx + 1][0][trans]);
          }
          dp[idx][buy][trans] = profit;
        }
      }
    }
    return dp[0][1][2];
  }
};

// 4. Space Optimized            |  T: O(n)    S: O(1)
class SpaceOptimized {
public:
  int maxProfit(vector<int> &prices) {
    int n = prices.size();
    vector<vector<int>> curr(2, vector<int>(3, 0)), prev(2, vector<int>(3, 0));
    for (int idx = 0; idx < n + 1; idx++) {
      for (int buy = 0; buy < 2; buy++) {
        prev[buy][0] = 0;
      }
    }
    for (int buy = 0; buy < 2; buy++) {
      for (int trans = 0; trans < 3; trans++) {
        prev[buy][trans] = 0;
      }
    }
    for (int idx = n - 1; idx >= 0; idx--) {
      for (int buy = 0; buy < 2; buy++) {
        for (int trans = 1; trans < 3; trans++) {
          int profit;
          if (buy) {
            profit = max(-prices[idx] + prev[0][trans], prev[1][trans]);
          } else {
            profit = max(prices[idx] + prev[1][trans - 1], prev[0][trans]);
          }
          curr[buy][trans] = profit;
        }
      }
      prev = curr;
    }
    return prev[1][2];
  }
};
