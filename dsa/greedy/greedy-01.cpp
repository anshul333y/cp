#include <bits/stdc++.h>
using namespace std;

// ── Assign Cookies ───────────────────────────────────────────

// T: O(n log n + m log m) S: O(1)
class Solution {
public:
  int findContentChildren(vector<int> &g, vector<int> &s) {
    int n = s.size(), m = g.size();

    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int l = 0, r = 0;

    while (r < n && l < m) {
      if (g[l] <= s[r]) {
        l++;
      }
      r++;
    }

    return l;
  }
};
