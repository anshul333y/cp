#include <bits/stdc++.h>
using namespace std;

// ── Longest Substring Without Repeating Characters ──────────────

// T: O(n)  S: O(min(n, charset))
class SlidingWindow {
public:
  int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> hash;
    int n = s.size();
    int l = 0, r = 0;

    int ans = 0;
    while (r < n) {
      hash[s[r]]++;

      while (hash.size() < r - l + 1) {
        hash[s[l]]--;
        if (hash[s[l]] == 0) {
          hash.erase(s[l]);
        }
        l++;
      }

      ans = max(ans, r - l + 1);
      r++;
    }

    return ans;
  }
};
