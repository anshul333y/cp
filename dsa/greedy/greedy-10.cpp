#include <bits/stdc++.h>
using namespace std;

// ── Minimum Platforms ────────────────────────────────────────

// T: O(n log n) S: O(1)
class Solution {
public:
  int minPlatform(vector<int> &Arrival, vector<int> &Departure) {
    int n = Arrival.size();

    sort(Arrival.begin(), Arrival.end());
    sort(Departure.begin(), Departure.end());

    int ptr1 = 0, ptr2 = 0;

    int ans = INT_MIN, count = 0;
    while (ptr1 < n) {
      if (Arrival[ptr1] <= Departure[ptr2]) {
        count++;
        ptr1++;
      } else {
        count--;
        ptr2++;
      }
      ans = max(ans, count);
    }

    return ans;
  }
};
