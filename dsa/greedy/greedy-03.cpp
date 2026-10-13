#include <bits/stdc++.h>
using namespace std;

// ── Minimum Average Waiting Time ─────────────────────────────

// T: O(n log n) S: O(1)
class Solution {
public:
  int solve(vector<int> &bt) {
    int n = bt.size();
    int waitTime = 0, sumWaitTime = 0;

    sort(bt.begin(), bt.end());

    for (int i = 0; i < n; i++) {
      sumWaitTime += waitTime;
      waitTime += bt[i];
    }

    return sumWaitTime / n;
  }
};
