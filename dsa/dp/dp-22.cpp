#include <bits/stdc++.h>
using namespace std;

// ── Coin Change II ───────────────────────────────────────────

// 1. Recursion                  |  T: O(2^amount)  S: O(amount)
class Recursion {
private:
  int rec(int idx, int amount, vector<int> &coins) {
    if (idx == 0) {
      if (amount % coins[idx] == 0)
        return 1;
      else
        return 0;
    }
    int take = 0;
    if (amount >= coins[idx])
      take = rec(idx, amount - coins[idx], coins);
    int notTake = rec(idx - 1, amount, coins);
    return take + notTake;
  }

public:
  int change(int amount, vector<int> &coins) {
    int n = coins.size();
    return rec(n - 1, amount, coins);
  }
};

// 2. Memoization (top-down DP)  |  T: O(n*amount)  S: O(n*amount)
class Memoization {
private:
  int rec(int idx, int amount, vector<int> &coins, vector<vector<int>> &dp) {
    if (idx == 0) {
      if (amount % coins[idx] == 0)
        return 1;
      else
        return 0;
    }
    if (dp[idx][amount] != -1)
      return dp[idx][amount];
    int take = 0;
    if (amount >= coins[idx])
      take = rec(idx, amount - coins[idx], coins, dp);
    int notTake = rec(idx - 1, amount, coins, dp);
    return dp[idx][amount] = take + notTake;
  }

public:
  int change(int amount, vector<int> &coins) {
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    return rec(n - 1, amount, coins, dp);
  }
};

// 3. Tabulation (bottom-up DP)  |  T: O(n*amount)  S: O(n*amount)
class Tabulation {
public:
  int change(int amount, vector<int> &coins) {
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
    for (int idx = 0; idx < n; idx++) {
      for (int amt = 0; amt < amount + 1; amt++) {
        if (idx == 0) {
          if (amt % coins[idx] == 0)
            dp[idx][amt] = 1;
        } else {
          int take = 0;
          if (amt >= coins[idx])
            take = dp[idx][amt - coins[idx]];
          int notTake = dp[idx - 1][amt];
          dp[idx][amt] = take + notTake;
        }
      }
    }
    return dp[n - 1][amount];
  }
};

// 4. Space Optimized            |  T: O(n*amount)  S: O(amount)
class SpaceOptimized {
public:
  int change(int amount, vector<int> &coins) {
    int n = coins.size();
    vector<int> dp(amount + 1, 0);
    for (int idx = 0; idx < n; idx++) {
      for (int amt = 0; amt < amount + 1; amt++) {
        if (idx == 0) {
          if (amt % coins[idx] == 0)
            dp[amt] = 1;
        } else {
          int take = 0;
          if (amt >= coins[idx])
            take = dp[amt - coins[idx]];
          int notTake = dp[amt];
          dp[amt] = take + notTake;
        }
      }
    }
    return dp[amount];
  }
};
