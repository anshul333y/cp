#include <bits/stdc++.h>
using namespace std;

// ── Print Shortest Common Supersequence ───────────────────────

// 1. Recursion                  |  T: O(2^n)  S: O(n)
class Recursion {};

// 2. Memoization (top-down DP)  |  T: O(n)    S: O(n)
class Memoization {};

// 3. Tabulation (bottom-up DP)  |  T: O(n*m)  S: O(n*m)
class Tabulation {
public:
  string shortestCommonSupersequence(string str1, string str2) {
    int size1 = str1.size(), size2 = str2.size();
    vector<vector<int>> dp(size1 + 1, vector<int>(size2 + 1, -1));
    for (int idx1 = 0; idx1 < size1 + 1; idx1++) {
      for (int idx2 = 0; idx2 < size2 + 1; idx2++) {
        if (idx1 == 0 || idx2 == 0) {
          dp[idx1][idx2] = 0;
        } else {
          int ans;
          if (str1[idx1 - 1] == str2[idx2 - 1])
            ans = 1 + dp[idx1 - 1][idx2 - 1];
          else
            ans = max(dp[idx1 - 1][idx2], dp[idx1][idx2 - 1]);
          dp[idx1][idx2] = ans;
        }
      }
    }
    int len = size1 + size2 - dp[size1][size2];
    string ans;
    for (int i = 0; i < len; i++)
      ans.push_back('$');
    int i = size1, j = size2;
    while (i && j) {
      if (str1[i - 1] == str2[j - 1]) {
        ans[len - 1] = str1[i - 1];
        i--;
        j--;
        len--;
      } else if (dp[i - 1][j] > dp[i][j - 1]) {
        ans[len - 1] = str1[i - 1];
        len--;
        i--;
      } else {
        ans[len - 1] = str2[j - 1];
        len--;
        j--;
      }
    }
    while (i) {
      ans[len - 1] = str1[i - 1];
      len--;
      i--;
    }
    while (j) {
      ans[len - 1] = str2[j - 1];
      len--;
      j--;
    }
    return ans;
  }
};

// 4. Space Optimized            |  T: O(n)    S: O(1)
class SpaceOptimized {};
