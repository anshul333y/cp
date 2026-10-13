#include <bits/stdc++.h>
using namespace std;

// ── Job Sequencing Problem ───────────────────────────────────

// T: O(n log n) S: O(n)
class Solution {
public:
  vector<int> JobScheduling(vector<vector<int>> &jobs) {
    int n = jobs.size();

    vector<int> vis(n, -1);
    int count = 0, maxProfit = 0;

    sort(jobs.begin(), jobs.end(),
         [](vector<int> &a, vector<int> &b) { return a[2] > b[2]; });

    for (int i = 0; i < n; i++) {
      int jobId = jobs[i][0];
      int deadLine = jobs[i][1];
      int profit = jobs[i][2];

      for (int j = deadLine - 1; j >= 0; j--) {
        if (vis[j] == -1) {
          maxProfit += profit;
          vis[j] = jobId;
          count++;
          break;
        }
      }
    }

    return {count, maxProfit};
  }
};
