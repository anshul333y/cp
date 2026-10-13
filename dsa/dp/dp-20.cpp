#include <bits/stdc++.h>
using namespace std;

// ── Coin Change ──────────────────────────────────────────────

// 1. Recursion                  |  T: O(2^amount)  S: O(amount)
class Recursion {
private:
  int rec(int idx, int amount, vector<int> &coins) {
    if (idx == 0) {
      if (amount % coins[idx] == 0)
        return amount / coins[idx];
      else
        return INT_MAX;
    }
    int take = INT_MAX, temp = INT_MAX;
    if (amount >= coins[idx])
      temp = rec(idx, amount - coins[idx], coins);
    if (temp != INT_MAX)
      take = 1 + temp;
    int notTake = rec(idx - 1, amount, coins);
    return min(take, notTake);
  }

public:
  int coinChange(vector<int> &coins, int amount) {
    int n = coins.size();
    int ans = rec(n - 1, amount, coins);
    if (ans == INT_MAX)
      return -1;
    return ans;
  }
};

// 2. Memoization (top-down DP)  |  T: O(n*amount)  S: O(n*amount)
class Memoization {
private:
  int rec(int idx, int amount, vector<int> &coins, vector<vector<int>> &dp) {
    if (idx == 0) {
      if (amount % coins[idx] == 0)
        return amount / coins[idx];
      else
        return INT_MAX;
    }
    if (dp[idx][amount] != -1)
      return dp[idx][amount];
    int take = INT_MAX, temp = INT_MAX;
    if (amount >= coins[idx])
      temp = rec(idx, amount - coins[idx], coins, dp);
    if (temp != INT_MAX)
      take = 1 + temp;
    int notTake = rec(idx - 1, amount, coins, dp);
    return dp[idx][amount] = min(take, notTake);
  }

public:
  int coinChange(vector<int> &coins, int amount) {
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    int ans = rec(n - 1, amount, coins, dp);
    if (ans == INT_MAX)
      return -1;
    return ans;
  }
};

// 3. Tabulation (bottom-up DP)  |  T: O(n*amount)  S: O(n*amount)
class Tabulation {
public:
  int coinChange(vector<int> &coins, int amount) {
    int n = coins.size();
    int target = amount + 1;
    vector<vector<int>> dp(n, vector<int>(target, -1));
    for (int idx = 0; idx < n; idx++) {
      for (int amt = 0; amt < target; amt++) {
        if (idx == 0) {
          if (amt % coins[idx] == 0)
            dp[idx][amt] = amt / coins[idx];
          else
            dp[idx][amt] = INT_MAX;
        } else {
          int take = INT_MAX, temp = INT_MAX;
          if (amt >= coins[idx])
            temp = dp[idx][amt - coins[idx]];
          if (temp != INT_MAX)
            take = 1 + temp;
          int notTake = dp[idx - 1][amt];
          dp[idx][amt] = min(take, notTake);
        }
      }
    }
    int ans = dp[n - 1][amount];
    if (ans == INT_MAX)
      return -1;
    return ans;
  }
};

// 4. Space Optimized            |  T: O(n*amount)  S: O(amount)
class SpaceOptimized {
public:
  int coinChange(vector<int> &coins, int amount) {
    int n = coins.size();
    int target = amount + 1;
    vector<int> dp(target, -1);
    for (int idx = 0; idx < n; idx++) {
      for (int amt = 0; amt < target; amt++) {
        if (idx == 0) {
          if (amt % coins[idx] == 0)
            dp[amt] = amt / coins[idx];
          else
            dp[amt] = INT_MAX;
        } else {
          int take = INT_MAX, temp = INT_MAX;
          if (amt >= coins[idx])
            temp = dp[amt - coins[idx]];
          if (temp != INT_MAX)
            take = 1 + temp;
          int notTake = dp[amt];
          dp[amt] = min(take, notTake);
        }
      }
    }
    int ans = dp[amount];
    if (ans == INT_MAX)
      return -1;
    return ans;
  }
};
