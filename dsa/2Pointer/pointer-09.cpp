#include <bits/stdc++.h>
using namespace std;

// ── Binary Subarrays With Sum ─────────────────────────────────────

// T: O(n²) S: O(1)
class brute {
public:
  int numSubarraysWithSum(vector<int> &nums, int goal) {
    int n = nums.size();

    int ans = 0;
    for (int i = 0; i < n; i++) {
      int sum = 0;
      for (int j = i; j < n; j++) {
        sum += nums[j];

        if (sum == goal) {
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
  int numSubarraysWithSum(vector<int> &nums, int goal) {
    int n = nums.size();

    int ans = 0;
    for (int i = 0; i < n; i++) {
      int sum = 0;
      for (int j = i; j < n; j++) {
        sum += nums[j];

        if (sum > goal) {
          break;
        }

        if (sum == goal) {
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
  int helper(vector<int> &nums, int goal) {
    int n = nums.size();
    int l = 0, r = 0;

    int ans = 0, sum = 0;
    while (r < n) {
      sum += nums[r];

      while (sum > goal) {
        sum -= nums[l];
        l++;
      }

      ans += r - l + 1;

      r++;
    }

    return ans;
  }

public:
  int numSubarraysWithSum(vector<int> &nums, int goal) {
    if (goal == 0)
      return helper(nums, goal);
    return helper(nums, goal) - helper(nums, goal - 1);
  }
};
