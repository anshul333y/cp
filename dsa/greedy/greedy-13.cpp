#include <bits/stdc++.h>
using namespace std;

// ── Fractional Knapsack ──────────────────────────────────────

// T: O(n log n) S: O(n)
class Solution {
public:
  double fractionalKnapsack(vector<int> &val, vector<int> &wt, int capacity) {
    int n = val.size();

    vector<pair<int, int>> data;

    for (int i = 0; i < n; i++) {
      data.push_back({val[i], wt[i]});
    }

    sort(data.begin(), data.end(), [](pair<int, int> &a, pair<int, int> &b) {
      return (double)a.first / a.second > (double)b.first / b.second;
    });

    double ans = 0;
    for (auto it : data) {
      if (it.second <= capacity) {
        ans += it.first;
        capacity -= it.second;
      } else {
        ans += (double)it.first / it.second * capacity;
        break;
      }
    }

    return ans;
  }
};
