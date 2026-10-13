#include <bits/stdc++.h>
using namespace std;

// ── Maximum Meetings in One Room ─────────────────────────────

// T: O(n log n) S: O(n)
class Solution {
public:
  vector<int> maxMeetings(vector<int> &start, vector<int> &end) {
    int n = start.size();

    vector<vector<int>> meet;

    for (int i = 0; i < n; i++) {
      meet.push_back({i + 1, start[i], end[i]});
    }

    sort(meet.begin(), meet.end(),
         [](vector<int> &a, vector<int> &b) { return a[2] < b[2]; });

    vector<int> ans;

    int last = INT_MIN;
    for (int i = 0; i < n; i++) {
      if (meet[i][1] > last) {
        ans.push_back(meet[i][0]);
        last = meet[i][2];
      }
    }

    sort(ans.begin(), ans.end());

    return ans;
  }
};
