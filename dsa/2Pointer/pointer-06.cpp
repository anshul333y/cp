#include <bits/stdc++.h>
using namespace std;

// ── Longest K Unique Characters Substring ────────────────────────

// T: O(n)  S: O(k)
class SlidingWindow {
public:
  int longestKSubstr(string &s, int k) {
    unordered_map<char, int> hash;
    int n = s.size();
    int l = 0, r = 0;

    int ans = -1;
    while (r < n) {
      hash[s[r]]++;

      while (hash.size() > k) {
        hash[s[l]]--;
        if (hash[s[l]] == 0) {
          hash.erase(s[l]);
        }
        l++;
      }

      if (hash.size() == k) {
        ans = max(ans, r - l + 1);
      }

      r++;
    }

    return ans;
  }
};
