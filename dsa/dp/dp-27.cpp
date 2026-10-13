#include <bits/stdc++.h>
using namespace std;

// ── Longest Common Substring ──────────────────────────────────

// 1. Recursion                  |  T: O(2^n)  S: O(n)
class Recursion {};

// 2. Memoization (top-down DP)  |  T: O(n)    S: O(n)
class Memoization {};

// 3. Tabulation (bottom-up DP)  |  T: O(n*m)  S: O(n*m)
class Tabulation {
public:
  int longCommSubstr(string &str1, string &str2) {
    int size1 = str1.size(), size2 = str2.size();
    vector<vector<int>> dp(size1 + 1, vector<int>(size2 + 1, 0));
    int ans = 0;
    for (int idx1 = 0; idx1 < size1 + 1; idx1++) {
      for (int idx2 = 0; idx2 < size2 + 1; idx2++) {
        if (idx1 == 0 || idx2 == 0) {
          dp[idx1][idx2] = 0;
        } else {
          if (str1[idx1 - 1] == str2[idx2 - 1]) {
            dp[idx1][idx2] = 1 + dp[idx1 - 1][idx2 - 1];
            ans = max(ans, dp[idx1][idx2]);
          } else
            dp[idx1][idx2] = 0;
        }
      }
    }
    return ans;
  }
};

// 4. Space Optimized            |  T: O(n*m)  S: O(m)
class SpaceOptimized {
public:
  int longCommSubstr(string &str1, string &str2) {
    int size1 = str1.size(), size2 = str2.size();
    vector<int> prev(size2 + 1, 0);
    int ans = 0;
    for (int idx1 = 0; idx1 < size1 + 1; idx1++) {
      vector<int> curr(size2 + 1, 0);
      for (int idx2 = 0; idx2 < size2 + 1; idx2++) {
        if (idx1 == 0 || idx2 == 0) {
          curr[idx2] = 0;
        } else {
          if (str1[idx1 - 1] == str2[idx2 - 1]) {
            curr[idx2] = 1 + prev[idx2 - 1];
            ans = max(ans, curr[idx2]);
          } else
            curr[idx2] = 0;
        }
      }
      prev = curr;
    }
    return ans;
  }
};
