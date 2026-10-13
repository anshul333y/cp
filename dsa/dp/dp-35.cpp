#include <bits/stdc++.h>
using namespace std;

// ── Best Time to Buy and Sell Stock ───────────────────────────

// 1. Recursion                  |  T: O(2^n)  S: O(n)
class Recursion {};

// 2. Memoization (top-down DP)  |  T: O(n)    S: O(n)
class Memoization {};

// 3. Tabulation (bottom-up DP)  |  T: O(n)    S: O(n)
class Tabulation {};

// 4. Space Optimized            |  T: O(n)    S: O(1)
class SpaceOptimized {
public:
  int maxProfit(vector<int> &prices) {
    int n = prices.size();
    int mini = INT_MAX;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      mini = min(mini, prices[i]);
      ans = max(ans, prices[i] - mini);
    }
    return ans;
  }
};
