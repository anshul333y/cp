#include <bits/stdc++.h>
using namespace std;

// ── Longest Palindromic Subsequence ───────────────────────────

// 1. Recursion                  |  T: O(2^n)  S: O(n)
class Recursion {
private:
  int fun(int idx1, int idx2, string &s1, string &s2) {
    if (idx1 == -1 || idx2 == -1)
      return 0;
    if (s1[idx1] == s2[idx2])
      return 1 + fun(idx1 - 1, idx2 - 1, s1, s2);
    else
      return max(fun(idx1 - 1, idx2, s1, s2), fun(idx1, idx2 - 1, s1, s2));
  }

public:
  int longestPalindromeSubseq(string s) {
    string s2 = s;
    reverse(s2.begin(), s2.end());
    int idx1 = s.size(), idx2 = idx1;
    return fun(idx1 - 1, idx2 - 1, s, s2);
  }
};

// 2. Memoization (top-down DP)  |  T: O(n^2)  S: O(n^2)
class Memoization {
private:
  int fun(int idx1, int idx2, string &s1, string &s2, vector<vector<int>> &dp) {
    if (idx1 == -1 || idx2 == -1)
      return 0;
    if (dp[idx1][idx2] != -1)
      return dp[idx1][idx2];
    if (s1[idx1] == s2[idx2])
      return dp[idx1][idx2] = 1 + fun(idx1 - 1, idx2 - 1, s1, s2, dp);
    else
      return dp[idx1][idx2] = max(fun(idx1 - 1, idx2, s1, s2, dp),
                                  fun(idx1, idx2 - 1, s1, s2, dp));
  }

public:
  int longestPalindromeSubseq(string s) {
    string s2 = s;
    reverse(s2.begin(), s2.end());
    int idx1 = s.size(), idx2 = idx1;
    vector<vector<int>> dp(idx1, vector<int>(idx2, -1));
    return fun(idx1 - 1, idx2 - 1, s, s2, dp);
  }
};

// 3. Tabulation (bottom-up DP)  |  T: O(n^2)  S: O(n^2)
class Tabulation {
public:
  int longestPalindromeSubseq(string s) {
    string s1 = s;
    string s2 = s;
    reverse(s2.begin(), s2.end());
    int size1 = s.size(), size2 = size1;
    vector<vector<int>> dp(size1 + 1, vector<int>(size2 + 1, 0));
    for (int idx1 = 0; idx1 < size1 + 1; idx1++) {
      for (int idx2 = 0; idx2 < size2 + 1; idx2++) {
        if (idx1 == 0 || idx2 == 0)
          dp[idx1][idx2] = 0;
        else {
          if (s1[idx1 - 1] == s2[idx2 - 1])
            dp[idx1][idx2] = 1 + dp[idx1 - 1][idx2 - 1];
          else
            dp[idx1][idx2] = max(dp[idx1 - 1][idx2], dp[idx1][idx2 - 1]);
        }
      }
    }
    return dp[size1][size2];
  }
};

// 4. Space Optimized            |  T: O(n^2)  S: O(n)
class SpaceOptimized {
public:
  int longestPalindromeSubseq(string s) {
    string s1 = s;
    string s2 = s;
    reverse(s2.begin(), s2.end());
    int size1 = s.size(), size2 = size1;
    vector<int> curr(size2 + 1, 0), prev(size2 + 1, 0);
    for (int idx1 = 0; idx1 < size1 + 1; idx1++) {
      for (int idx2 = 0; idx2 < size2 + 1; idx2++) {
        if (idx1 == 0 || idx2 == 0)
          curr[idx2] = 0;
        else {
          if (s1[idx1 - 1] == s2[idx2 - 1])
            curr[idx2] = 1 + prev[idx2 - 1];
          else
            curr[idx2] = max(prev[idx2], curr[idx2 - 1]);
        }
      }
      prev = curr;
    }
    return prev[size2];
  }
};
