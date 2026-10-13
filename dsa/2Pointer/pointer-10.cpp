#include <bits/stdc++.h>
using namespace std;

// ── Count Number of Nice Subarrays ───────────────────────────────

// T: O(n²) S: O(1)
class brute {
public:
  int numberOfSubarrays(vector<int> &nums, int k) {
    int n = nums.size();

    int ans = 0;
    for (int i = 0; i < n; i++) {
      int count = 0;
      for (int j = i; j < n; j++) {
        if (nums[j] % 2 == 1) {
          count++;
        }

        if (count == k) {
          ans++;
        }
      }
    }

    return ans;
  }
};

// T: O(n²)  S: O(1)
class better {
public:
  int numberOfSubarrays(vector<int> &nums, int k) {
    int n = nums.size();

    int ans = 0;
    for (int i = 0; i < n; i++) {
      int count = 0;
      for (int j = i; j < n; j++) {
        if (nums[j] % 2 == 1) {
          count++;
        }

        if (count > k) {
          break;
        }

        if (count == k) {
          ans++;
        }
      }
    }

    return ans;
  }
};

// T: O(n)  S: O(1)
class optimal {
private:
  int helper(vector<int> &nums, int k) {
    int n = nums.size();
    int l = 0, r = 0;

    int ans = 0, count = 0;
    while (r < n) {
      if (nums[r] % 2 != 0) {
        count++;
      }

      while (count > k) {
        if (nums[l] % 2 != 0) {
          count--;
        }
        l++;
      }

      ans += r - l + 1;

      r++;
    }

    return ans;
  }

public:
  int numberOfSubarrays(vector<int> &nums, int k) {
    return helper(nums, k) - helper(nums, k - 1);
  }
};
