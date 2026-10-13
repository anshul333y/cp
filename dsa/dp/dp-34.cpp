#include <bits/stdc++.h>
using namespace std;

// ── Wildcard Matching ──────────────────────────────────────────

// 1. Recursion                  |  T: O(2^n)  S: O(n)
class Recursion {
private:
  bool fun(int idx1, int idx2, string &s, string &p) {
    if (idx1 == 0 && idx2 == 0)
      return true;
    else if (idx2 == 0)
      return false;
    else if (idx1 == 0 && idx2 > 0) {
      for (int i = 0; i < idx2; i++)
        if (p[i] != '*')
          return false;
      return true;
    }
    if (s[idx1 - 1] == p[idx2 - 1] || p[idx2 - 1] == '?')
      return fun(idx1 - 1, idx2 - 1, s, p);
    else if (p[idx2 - 1] == '*')
      return fun(idx1 - 1, idx2, s, p) || fun(idx1, idx2 - 1, s, p);
    else
      return false;
  }

public:
  bool isMatch(string s, string p) {
    int n = s.size(), m = p.size();
    return fun(n, m, s, p);
  }
};

// 2. Memoization (top-down DP)  |  T: O(n*m)  S: O(n*m)
class Memoization {
private:
  bool fun(int idx1, int idx2, string &s, string &p, vector<vector<int>> &dp) {
    if (idx1 == 0 && idx2 == 0)
      return true;
    else if (idx2 == 0)
      return false;
    else if (idx1 == 0 && idx2 > 0) {
      for (int i = 0; i < idx2; i++)
        if (p[i] != '*')
          return false;
      return true;
    }
    if (dp[idx1][idx2] != -1)
      return dp[idx1][idx2];
    if (s[idx1 - 1] == p[idx2 - 1] || p[idx2 - 1] == '?')
      return dp[idx1][idx2] = fun(idx1 - 1, idx2 - 1, s, p, dp);
    else if (p[idx2 - 1] == '*')
      return dp[idx1][idx2] =
                 fun(idx1 - 1, idx2, s, p, dp) || fun(idx1, idx2 - 1, s, p, dp);
    else
      return dp[idx1][idx2] = false;
  }

public:
  bool isMatch(string s, string p) {
    int n = s.size(), m = p.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return fun(n, m, s, p, dp);
  }
};

// 3. Tabulation (bottom-up DP)  |  T: O(n*m)  S: O(n*m)
class Tabulation {
public:
  bool isMatch(string s, string p) {
    int n = s.size(), m = p.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int idx1 = 0; idx1 < n + 1; idx1++) {
      for (int idx2 = 0; idx2 < m + 1; idx2++) {
        if (idx1 == 0 || idx2 == 0) {
          if (idx1 == 0 && idx2 == 0)
            dp[idx1][idx2] = true;
          else if (idx2 == 0)
            dp[idx1][idx2] = false;
          else if (idx1 == 0 && idx2 > 0) {
            dp[idx1][idx2] = true;
            for (int i = 0; i < idx2; i++)
              if (p[i] != '*')
                dp[idx1][idx2] = false;
          }
        } else {
          if (s[idx1 - 1] == p[idx2 - 1] || p[idx2 - 1] == '?')
            dp[idx1][idx2] = dp[idx1 - 1][idx2 - 1];
          else if (p[idx2 - 1] == '*')
            dp[idx1][idx2] = dp[idx1 - 1][idx2] || dp[idx1][idx2 - 1];
          else
            dp[idx1][idx2] = false;
        }
      }
    }
    return dp[n][m];
  }
};

// 4. Space Optimized            |  T: O(n*m)  S: O(m)
class SpaceOptimized {
public:
  bool isMatch(string s, string p) {
    int n = s.size(), m = p.size();
    vector<int> prev(m + 1, 0), curr(m + 1, 0);
    for (int idx1 = 0; idx1 < n + 1; idx1++) {
      for (int idx2 = 0; idx2 < m + 1; idx2++) {
        if (idx1 == 0 || idx2 == 0) {
          if (idx1 == 0 && idx2 == 0)
            curr[idx2] = true;
          else if (idx2 == 0)
            curr[idx2] = false;
          else if (idx1 == 0 && idx2 > 0) {
            curr[idx2] = true;
            for (int i = 0; i < idx2; i++)
              if (p[i] != '*')
                curr[idx2] = false;
          }
        } else {
          if (s[idx1 - 1] == p[idx2 - 1] || p[idx2 - 1] == '?')
            curr[idx2] = prev[idx2 - 1];
          else if (p[idx2 - 1] == '*')
            curr[idx2] = prev[idx2] || curr[idx2 - 1];
          else
            curr[idx2] = false;
        }
      }
      prev = curr;
    }
    return prev[m];
  }
};
