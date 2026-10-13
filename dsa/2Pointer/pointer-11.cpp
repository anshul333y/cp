#include <bits/stdc++.h>
using namespace std;

// ── Subarrays with K Different Integers ──────────────────────────

// T: O(n²)  S: O(n)
class brute {
public:
  int subarraysWithKDistinct(vector<int> &nums, int k) {
    int n = nums.size();

    int ans = 0;
    for (int i = 0; i < n; i++) {
      unordered_map<int, int> hash;
      for (int j = i; j < n; j++) {
        hash[nums[j]]++;

        if (hash.size() == k) {
          ans++;
        }
      }
    }

    return ans;
  }
};

// T: O(n²)  S: O(n)
class better {
public:
  int subarraysWithKDistinct(vector<int> &nums, int k) {
    int n = nums.size();

    int ans = 0;
    for (int i = 0; i < n; i++) {
      unordered_map<int, int> hash;
      for (int j = i; j < n; j++) {
        hash[nums[j]]++;

        if (hash.size() > k) {
          break;
        }

        if (hash.size() == k) {
          ans++;
        }
      }
    }

    return ans;
  }
};

// T: O(n)  S: O(n)
class optimal {
private:
  int helper(vector<int> &nums, int k) {
    int n = nums.size();
    unordered_map<int, int> hash;
    int l = 0, r = 0;

    int ans = 0;
    while (r < n) {
      hash[nums[r]]++;

      while (hash.size() > k) {
        hash[nums[l]]--;
        if (hash[nums[l]] == 0) {
          hash.erase(nums[l]);
        }
        l++;
      }

      ans += r - l + 1;

      r++;
    }

    return ans;
  }

public:
  int subarraysWithKDistinct(vector<int> &nums, int k) {
    return helper(nums, k) - helper(nums, k - 1);
  }
};
