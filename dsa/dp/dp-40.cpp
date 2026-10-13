#include <bits/stdc++.h>
using namespace std;

// ── Best Time to Buy and Sell Stock with Transaction Fee ──────

// 1. Recursion                  |  T: O(2^n)  S: O(n)
class Recursion {};

// 2. Memoization (top-down DP)  |  T: O(n)    S: O(n)
class Memoization {};

// 3. Tabulation (bottom-up DP)  |  T: O(n)    S: O(n)
class Tabulation {};

// 4. Space Optimized            |  T: O(n)    S: O(1)
class SpaceOptimized {
public:
  int maxProfit(vector<int> &prices, int fee) {
    int n = prices.size();
    vector<int> curr(2, 0), prev(2, 0);
    prev[0] = 0, prev[1] = 0;
    for (int idx = n - 1; idx >= 0; idx--) {
      for (int buy = 0; buy < 2; buy++) {
        int profit;
        if (buy) {
          profit = max(-prices[idx] + prev[0], prev[1]);
        } else {
          profit = max(prices[idx] - fee + prev[1], prev[0]);
        }
        curr[buy] = profit;
      }
      prev = curr;
    }
    return prev[1];
  }
};
