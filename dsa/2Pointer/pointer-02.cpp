#include <bits/stdc++.h>
using namespace std;

// ── Maximum Points You Can Obtain from Cards ────────────────────

// T: O(k)  S: O(1)
class SlidingWindow {
public:
  int maxScore(vector<int> &cardPoints, int k) {
    int n = cardPoints.size();
    int lSum = 0, rSum = 0, l = 0, r = 0;

    while (l < k) {
      lSum += cardPoints[l];
      l++;
    }
    l--;

    int ans = lSum;

    while (r < k) {
      rSum += cardPoints[n - 1 - r];
      lSum -= cardPoints[l];
      ans = max(ans, lSum + rSum);
      l--;
      r++;
    }

    return ans;
  }
};
