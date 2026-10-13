#include <bits/stdc++.h>
using namespace std;

// ── Delete Operations for Two Strings ─────────────────────────

// 1. Recursion                  |  T: O(2^n)  S: O(n)
class Recursion {};

// 2. Memoization (top-down DP)  |  T: O(n)    S: O(n)
class Memoization {};

// 3. Tabulation (bottom-up DP)  |  T: O(n)    S: O(n)
class Tabulation {};

// 4. Space Optimized            |  T: O(n*m)  S: O(m)
class SpaceOptimized {
public:
  int minDistance(string word1, string word2) {
    string text1 = word1;
    string text2 = word2;
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
    return (size1 - prev[size2]) + (size2 - prev[size2]);
  }
};
