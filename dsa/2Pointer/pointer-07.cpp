#include <bits/stdc++.h>
using namespace std;

// ── Number of Substrings Containing All Three Characters ────────

// T: O(n²)  S: O(1)
class brute {
public:
  int numberOfSubstrings(string s) {
    unordered_map<char, int> hash;
    int n = s.size();

    int ans = 0;
    for (int i = 0; i < n; i++) {
      hash.clear();
      for (int j = i; j < n; j++) {
        hash[s[j]]++;
        if (hash.size() == 3) {
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
  int numberOfSubstrings(string s) {
    unordered_map<char, int> hash;
    int n = s.size();

    int ans = 0;
    for (int i = 0; i < n; i++) {
      hash.clear();
      for (int j = i; j < n; j++) {
        hash[s[j]]++;
        if (hash.size() == 3) {
          ans += (n - j);
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
  int numberOfSubstrings(string s) {
    vector<int> hash(3, -1);
    int n = s.size();
    int r = 0;

    int ans = 0;
    while (r < n) {
      hash[s[r] - 'a'] = r;

      if (hash[0] >= 0 && hash[1] >= 0 && hash[2] >= 0) {
        ans += (min({hash[0], hash[1], hash[2]}) + 1);
      }

      r++;
    }

    return ans;
  }
};
