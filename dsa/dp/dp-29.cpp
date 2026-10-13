#include <bits/stdc++.h>
using namespace std;

// ── Minimum Insertions to Make String Palindrome ──────────────

// 1. Recursion                  |  T: O(2^n)  S: O(n)
class Recursion {};

// 2. Memoization (top-down DP)  |  T: O(n)    S: O(n)
class Memoization {};

// 3. Tabulation (bottom-up DP)  |  T: O(n)    S: O(n)
class Tabulation {};

// 4. Space Optimized            |  T: O(n^2)  S: O(n)
class SpaceOptimized {
public:
  int minInsertions(string s) {
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
    return size1 - prev[size2];
  }
};
