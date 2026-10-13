#include <bits/stdc++.h>
using namespace std;

// ── Non-overlapping Intervals ────────────────────────────────

// T: O(n log n) S: O(n)
class Solution {
public:
  int eraseOverlapIntervals(vector<vector<int>> &intervals) {
    int n = intervals.size();
    vector<vector<int>> temp = intervals;

    sort(temp.begin(), temp.end(), [](vector<int> &a, vector<int> &b) {
      if (a[1] != b[1])
        return a[1] < b[1];
      else
        return a[0] > b[0];
    });

    int ans = 0, last = INT_MIN;
    for (int i = 0; i < n; i++) {
      if (temp[i][0] < last) {
        ans++;
      } else {
        last = temp[i][1];
      }
    }

    return ans;
  }
};
