#include <bits/stdc++.h>
using namespace std;

// ── Longest Repeating Character Replacement ──────────────────────

// T: O(n²)  S: O(1)
class brute {
public:
  int characterReplacement(string s, int k) {
    int n = s.size();

    int ans = 0;
    for (int i = 0; i < n; i++) {
      int maxFreq = 0;
      vector<int> hash(26, 0);
      for (int j = i; j < n; j++) {
        hash[s[j] - 'A']++;
        maxFreq = max(maxFreq, hash[s[j] - 'A']);
        if (j - i + 1 - maxFreq <= k) {
          ans = max(ans, j - i + 1);
        }
      }
    }

    return ans;
  }
};

// T: O(n²)  S: O(1)
class better {
public:
  int characterReplacement(string s, int k) {
    int n = s.size();

    int ans = 0;
    for (int i = 0; i < n; i++) {
      int maxFreq = 0;
      vector<int> hash(26, 0);
      for (int j = i; j < n; j++) {
        hash[s[j] - 'A']++;
        maxFreq = max(maxFreq, hash[s[j] - 'A']);
        if (j - i + 1 - maxFreq <= k) {
          ans = max(ans, j - i + 1);
        } else {
          break;
        }
      }
    }

    return ans;
  }
};

// T: O(n)  S: O(1)
class optimal {
public:
  int characterReplacement(string s, int k) {
    int n = s.size();
    int l = 0, r = 0;
    vector<int> hash(26, 0);

    int ans = 0, maxFreq = 0;
    while (r < n) {
      hash[s[r] - 'A']++;
      maxFreq = max(maxFreq, hash[s[r] - 'A']);

      while (r - l + 1 - maxFreq > k) {
        hash[s[l] - 'A']--;
        l++;
      }

      ans = max(ans, r - l + 1);
      r++;
    }

    return ans;
  }
};
