#include <bits/stdc++.h>
using namespace std;

// ── Distinct Subsequences ─────────────────────────────────────

// 1. Recursion                  |  T: O(2^n)  S: O(n)
class Recursion {
private:
  int fun(int idx1, int idx2, string &s, string &t) {
    if (idx2 == 0)
      return 1;
    else if (idx1 == 0)
      return 0;
    int equal = INT_MIN, notEqual = INT_MIN;
    if (s[idx1 - 1] == t[idx2 - 1])
      equal = fun(idx1 - 1, idx2 - 1, s, t) + fun(idx1 - 1, idx2, s, t);
    else
      notEqual = fun(idx1 - 1, idx2, s, t);
    return max(equal, notEqual);
  }

public:
  int numDistinct(string s, string t) {
    int n = s.size(), m = t.size();
    return fun(n, m, s, t);
  }
};

// 2. Memoization (top-down DP)  |  T: O(n*m)  S: O(n*m)
class Memoization {
private:
  int fun(int idx1, int idx2, string &s, string &t, vector<vector<int>> &dp) {
    if (idx2 == 0)
      return 1;
    else if (idx1 == 0)
      return 0;
    if (dp[idx1][idx2] != -1)
      return dp[idx1][idx2];
    int equal = INT_MIN, notEqual = INT_MIN;
    if (s[idx1 - 1] == t[idx2 - 1])
      equal = fun(idx1 - 1, idx2 - 1, s, t, dp) + fun(idx1 - 1, idx2, s, t, dp);
    else
      notEqual = fun(idx1 - 1, idx2, s, t, dp);
    return dp[idx1][idx2] = max(equal, notEqual);
  }

public:
  int numDistinct(string s, string t) {
    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return fun(n, m, s, t, dp);
  }
};

// 3. Tabulation (bottom-up DP)  |  T: O(n*m)  S: O(n*m)
class Tabulation {
public:
  int numDistinct(string s, string t) {
    int n = s.size(), m = t.size();
    vector<vector<double>> dp(n + 1, vector<double>(m + 1, 0));
    for (int idx1 = 0; idx1 < n + 1; idx1++) {
      for (int idx2 = 0; idx2 < m + 1; idx2++) {
        if (idx2 == 0 || idx1 == 0) {
          if (idx2 == 0)
            dp[idx1][idx2] = 1;
          else if (idx1 == 0)
            dp[idx1][idx2] = 0;
        } else {
          double equal = INT_MIN, notEqual = INT_MIN;
          if (s[idx1 - 1] == t[idx2 - 1])
            equal = dp[idx1 - 1][idx2 - 1] + dp[idx1 - 1][idx2];
          else
            notEqual = dp[idx1 - 1][idx2];
          dp[idx1][idx2] = max(equal, notEqual);
        }
      }
    }
    return dp[n][m];
  }
};

// 4. Space Optimized            |  T: O(n*m)  S: O(m)
class SpaceOptimized {
public:
  int numDistinct(string s, string t) {
    int n = s.size(), m = t.size();
    vector<double> dp(m + 1, 0);
    for (int idx1 = 0; idx1 < n + 1; idx1++) {
      for (int idx2 = m; idx2 >= 0; idx2--) {
        if (idx2 == 0 || idx1 == 0) {
          if (idx2 == 0)
            dp[idx2] = 1;
          else if (idx1 == 0)
            dp[idx2] = 0;
        } else {
          double equal = INT_MIN, notEqual = INT_MIN;
          if (s[idx1 - 1] == t[idx2 - 1])
            equal = dp[idx2 - 1] + dp[idx2];
          else
            notEqual = dp[idx2];
          dp[idx2] = max(equal, notEqual);
        }
      }
    }
    return dp[m];
  }
};
