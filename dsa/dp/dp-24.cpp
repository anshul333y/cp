#include <bits/stdc++.h>
using namespace std;

// ── Rod Cutting ──────────────────────────────────────────────

// 1. Recursion                  |  T: O(2^n)  S: O(n)
class Recursion {
private:
  int fun(int idx, int n, vector<int> &price) {
    if (idx == 0)
      return n * price[0];
    int take = INT_MIN;
    int rodLen = idx + 1;
    if (rodLen <= n)
      take = price[idx] + fun(idx, n - rodLen, price);
    int notTake = fun(idx - 1, n, price);
    return max(take, notTake);
  }

public:
  int cutRod(vector<int> &price) {
    int n = price.size();
    return fun(n - 1, n, price);
  }
};

// 2. Memoization (top-down DP)  |  T: O(n^2)  S: O(n^2)
class Memoization {
private:
  int fun(int idx, int n, vector<int> &price, vector<vector<int>> &dp) {
    if (idx == 0)
      return n * price[0];
    if (dp[idx][n] != -1)
      return dp[idx][n];
    int take = INT_MIN;
    int rodLen = idx + 1;
    if (rodLen <= n)
      take = price[idx] + fun(idx, n - rodLen, price, dp);
    int notTake = fun(idx - 1, n, price, dp);
    return dp[idx][n] = max(take, notTake);
  }

public:
  int cutRod(vector<int> &price) {
    int n = price.size();
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return fun(n - 1, n, price, dp);
  }
};

// 3. Tabulation (bottom-up DP)  |  T: O(n^2)  S: O(n^2)
class Tabulation {
public:
  int cutRod(vector<int> &price) {
    int size = price.size();
    vector<vector<int>> dp(size, vector<int>(size + 1, 0));
    for (int idx = 0; idx < size; idx++) {
      for (int n = 0; n < size + 1; n++) {
        if (idx == 0) {
          dp[idx][n] = n * price[0];
        } else {
          int take = INT_MIN;
          int rodLen = idx + 1;
          if (rodLen <= n)
            take = price[idx] + dp[idx][n - rodLen];
          int notTake = dp[idx - 1][n];
          dp[idx][n] = max(take, notTake);
        }
      }
    }
    return dp[size - 1][size];
  }
};

// 4. Space Optimized            |  T: O(n^2)  S: O(n)
class SpaceOptimized {
public:
  int cutRod(vector<int> &price) {
    int size = price.size();
    vector<int> dp(size + 1, 0);
    for (int idx = 0; idx < size; idx++) {
      for (int n = 0; n < size + 1; n++) {
        if (idx == 0) {
          dp[n] = n * price[0];
        } else {
          int take = INT_MIN;
          int rodLen = idx + 1;
          if (rodLen <= n)
            take = price[idx] + dp[n - rodLen];
          int notTake = dp[n];
          dp[n] = max(take, notTake);
        }
      }
    }
    return dp[size];
  }
};
