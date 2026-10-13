#include <bits/stdc++.h>
using namespace std;

// ── Insert Interval ──────────────────────────────────────────

// T: O(n) S: O(n)
class Solution {
public:
  vector<vector<int>> insert(vector<vector<int>> &intervals,
                             vector<int> &newInterval) {
    int n = intervals.size();
    vector<vector<int>> ans;

    int i = 0;
    while (i < n && intervals[i][1] < newInterval[0]) {
      ans.push_back(intervals[i]);
      i++;
    }

    int mini = newInterval[0], maxi = newInterval[1];
    while (i < n && intervals[i][0] <= newInterval[1]) {
      mini = min(mini, intervals[i][0]);
      maxi = max(maxi, intervals[i][1]);
      i++;
    }
    ans.push_back({mini, maxi});

    while (i < n) {
      ans.push_back(intervals[i]);
      i++;
    }

    return ans;
  }
};
