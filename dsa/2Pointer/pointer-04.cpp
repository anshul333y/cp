#include <bits/stdc++.h>
using namespace std;

// ── Max Consecutive Ones III ─────────────────────────────────────

// T: O(n)  S: O(1)
class SlidingWindow {
public:
  int longestOnes(vector<int> &nums, int k) {
    int n = nums.size();
    int l = 0, r = 0, zeros = 0;
    int ans = 0;

    while (r < n) {
      if (nums[r] == 0) {
        zeros++;
      }

      while (zeros > k) {
        if (nums[l] == 0) {
          zeros--;
        }
        l++;
      }

      ans = max(ans, r - l + 1);
      r++;
    }

    return ans;
  }
};
