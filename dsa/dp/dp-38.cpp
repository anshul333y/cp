#include <bits/stdc++.h>
using namespace std;

// ── Best Time to Buy and Sell Stock IV ────────────────────────

// 1. Recursion                  |  T: O(2^n)  S: O(n)
class Recursion {};

// 2. Memoization (top-down DP)  |  T: O(n)    S: O(n)
class Memoization {};

// 3. Tabulation (bottom-up DP)  |  T: O(n)    S: O(n)
class Tabulation {};

// 4. Space Optimized            |  T: O(n*k)  S: O(k)
class SpaceOptimized {
public:
  int maxProfit(int k, vector<int> &prices) {
    int n = prices.size();
    vector<vector<int>> curr(2, vector<int>(k + 1, 0)),
        prev(2, vector<int>(k + 1, 0));
    for (int idx = n - 1; idx >= 0; idx--) {
      for (int buy = 0; buy < 2; buy++) {
        for (int trans = 1; trans < k + 1; trans++) {
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
    return prev[1][k];
  }
};
