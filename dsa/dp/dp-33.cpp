#include <bits/stdc++.h>
using namespace std;

// ── Edit Distance ──────────────────────────────────────────────

// 1. Recursion                  |  T: O(3^n)  S: O(n)
class Recursion {
private:
  int fun(int idx1, int idx2, string &word1, string &word2) {
    if (idx2 == 0)
      return idx1;
    else if (idx1 == 0)
      return idx2;
    if (word1[idx1 - 1] == word2[idx2 - 1])
      return fun(idx1 - 1, idx2 - 1, word1, word2);
    int ans1 = 1 + fun(idx1, idx2 - 1, word1, word2);     // insert
    int ans2 = 1 + fun(idx1 - 1, idx2, word1, word2);     // delete
    int ans3 = 1 + fun(idx1 - 1, idx2 - 1, word1, word2); // replace
    return min({ans1, ans2, ans3});
  }

public:
  int minDistance(string word1, string word2) {
    int n = word1.size(), m = word2.size();
    return fun(n, m, word1, word2);
  }
};

// 2. Memoization (top-down DP)  |  T: O(n*m)  S: O(n*m)
class Memoization {
private:
  int fun(int idx1, int idx2, string &word1, string &word2,
          vector<vector<int>> &dp) {
    if (idx2 == 0)
      return idx1;
    else if (idx1 == 0)
      return idx2;
    if (dp[idx1][idx2] != -1)
      return dp[idx1][idx2];
    if (word1[idx1 - 1] == word2[idx2 - 1])
      return fun(idx1 - 1, idx2 - 1, word1, word2, dp);
    int ans1 = 1 + fun(idx1, idx2 - 1, word1, word2, dp);     // insert
    int ans2 = 1 + fun(idx1 - 1, idx2, word1, word2, dp);     // delete
    int ans3 = 1 + fun(idx1 - 1, idx2 - 1, word1, word2, dp); // replace
    return dp[idx1][idx2] = min({ans1, ans2, ans3});
  }

public:
  int minDistance(string word1, string word2) {
    int n = word1.size(), m = word2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return fun(n, m, word1, word2, dp);
  }
};

// 3. Tabulation (bottom-up DP)  |  T: O(n*m)  S: O(n*m)
class Tabulation {
public:
  int minDistance(string word1, string word2) {
    int n = word1.size(), m = word2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int idx1 = 0; idx1 < n + 1; idx1++) {
      for (int idx2 = 0; idx2 < m + 1; idx2++) {
        if (idx1 == 0 || idx2 == 0) {
          if (idx2 == 0)
            dp[idx1][idx2] = idx1;
          else if (idx1 == 0)
            dp[idx1][idx2] = idx2;
        } else {
          if (word1[idx1 - 1] == word2[idx2 - 1])
            dp[idx1][idx2] = dp[idx1 - 1][idx2 - 1];
          else {
            int ans1 = 1 + dp[idx1][idx2 - 1];
            int ans2 = 1 + dp[idx1 - 1][idx2];
            int ans3 = 1 + dp[idx1 - 1][idx2 - 1];
            dp[idx1][idx2] = min({ans1, ans2, ans3});
          }
        }
      }
    }
    return dp[n][m];
  }
};

// 4. Space Optimized            |  T: O(n*m)  S: O(m)
class SpaceOptimized {
public:
  int minDistance(string word1, string word2) {
    int n = word1.size(), m = word2.size();
    vector<int> curr(m + 1, 0), prev(m + 1, 0);
    for (int idx1 = 0; idx1 < n + 1; idx1++) {
      for (int idx2 = 0; idx2 < m + 1; idx2++) {
        if (idx1 == 0 || idx2 == 0) {
          if (idx2 == 0)
            curr[idx2] = idx1;
          else if (idx1 == 0)
            curr[idx2] = idx2;
        } else {
          if (word1[idx1 - 1] == word2[idx2 - 1])
            curr[idx2] = prev[idx2 - 1];
          else {
            int ans1 = 1 + curr[idx2 - 1];
            int ans2 = 1 + prev[idx2];
            int ans3 = 1 + prev[idx2 - 1];
            curr[idx2] = min({ans1, ans2, ans3});
          }
        }
      }
      prev = curr;
    }
    return prev[m];
  }
};
