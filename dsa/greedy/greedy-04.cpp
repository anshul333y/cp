#include <bits/stdc++.h>
using namespace std;

// ── Jump Game ────────────────────────────────────────────────

// T: O(n) S: O(1)
class Solution {
public:
  bool canJump(vector<int> &nums) {
    int n = nums.size();
    int maxIdx = 0;

    for (int i = 0; i < n; i++) {
      if (i > maxIdx)
        return false;

      maxIdx = max(maxIdx, i + nums[i]);
    }

    return true;
  }
};
