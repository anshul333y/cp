#include <bits/stdc++.h>
using namespace std;

// ── Longest Common Subsequence ─────────────────────────────────

// 1. Recursion                  |  T: O(2^(n+m))  S: O(n+m)
class Recursion {
private:
  int fun(int idx1, int idx2, string &text1, string &text2) {
    if (idx1 == 0 || idx2 == 0)
      return 0;
    int ans;
    if (text1[idx1 - 1] == text2[idx2 - 1])
      ans = 1 + fun(idx1 - 1, idx2 - 1, text1, text2);
    else
      ans = max(fun(idx1 - 1, idx2, text1, text2),
                fun(idx1, idx2 - 1, text1, text2));
    return ans;
  }

public:
  int longestCommonSubsequence(string text1, string text2) {
    int size1 = text1.size(), size2 = text2.size();
    return fun(size1, size2, text1, text2);
  }
};

// 2. Memoization (top-down DP)  |  T: O(n*m)  S: O(n*m)
class Memoization {
private:
  int fun(int idx1, int idx2, string &text1, string &text2,
          vector<vector<int>> &dp) {
    if (idx1 == 0 || idx2 == 0)
      return 0;
    if (dp[idx1][idx2] != -1)
      return dp[idx1][idx2];
    int ans;
    if (text1[idx1 - 1] == text2[idx2 - 1])
      ans = 1 + fun(idx1 - 1, idx2 - 1, text1, text2, dp);
    else
      ans = max(fun(idx1 - 1, idx2, text1, text2, dp),
                fun(idx1, idx2 - 1, text1, text2, dp));
    return dp[idx1][idx2] = ans;
  }

public:
  int longestCommonSubsequence(string text1, string text2) {
    int size1 = text1.size(), size2 = text2.size();
    vector<vector<int>> dp(size1 + 1, vector<int>(size2 + 1, -1));
    return fun(size1, size2, text1, text2, dp);
  }
};

// 3. Tabulation (bottom-up DP)  |  T: O(n*m)  S: O(n*m)
class Tabulation {
public:
  int longestCommonSubsequence(string text1, string text2) {
    int size1 = text1.size(), size2 = text2.size();
    vector<vector<int>> dp(size1 + 1, vector<int>(size2 + 1, 0));
    for (int idx1 = 0; idx1 < size1 + 1; idx1++) {
      for (int idx2 = 0; idx2 < size2 + 1; idx2++) {
        if (idx1 == 0 || idx2 == 0) {
          dp[idx1][idx2] = 0;
        } else {
          int ans;
          if (text1[idx1 - 1] == text2[idx2 - 1])
            ans = 1 + dp[idx1 - 1][idx2 - 1];
          else
            ans = max(dp[idx1 - 1][idx2], dp[idx1][idx2 - 1]);
          dp[idx1][idx2] = ans;
        }
      }
    }
    return dp[size1][size2];
  }
};

// 4. Space Optimized            |  T: O(n*m)  S: O(m)
class SpaceOptimized {
public:
  int longestCommonSubsequence(string text1, string text2) {
    int size1 = text1.size(), size2 = text2.size();
    vector<int> prev(size2 + 1, 0);
    for (int idx1 = 0; idx1 < size1 + 1; idx1++) {
      vector<int> curr(size2 + 1, 0);
      for (int idx2 = 0; idx2 < size2 + 1; idx2++) {
        if (idx1 == 0 || idx2 == 0) {
          curr[idx2] = 0;
        } else {
          int ans;
          if (text1[idx1 - 1] == text2[idx2 - 1])
            ans = 1 + prev[idx2 - 1];
          else
            ans = max(prev[idx2], curr[idx2 - 1]);
          curr[idx2] = ans;
        }
      }
      prev = curr;
    }
    return prev[size2];
  }
};
