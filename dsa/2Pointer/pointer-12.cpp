#include <bits/stdc++.h>
using namespace std;

// ── Minimum Window Substring ─────────────────────────────────────

// T: O(n² · m)  S: O(n + m)
class brute {
private:
  bool helper(unordered_map<char, int> &hash1,
              unordered_map<char, int> &hash2) {
    for (auto &[a, b] : hash2) {
      if (hash1[a] < b) {
        return false;
      }
    }

    return true;
  }

public:
  string minWindow(string s, string t) {
    if (s.size() < t.size()) {
      return "";
    }

    int n = s.size(), m = t.size();
    unordered_map<char, int> hash2;

    for (auto it : t) {
      hash2[it]++;
    }

    string ans;
    int min = INT_MAX;
    for (int i = 0; i < n; i++) {
      unordered_map<char, int> hash1;
      for (int j = i; j < n; j++) {
        hash1[s[j]]++;

        if (helper(hash1, hash2)) {
          if (j - i + 1 < min) {
            min = j - i + 1;
            ans.clear();

            for (int k = i; k <= j; k++) {
              ans.push_back(s[k]);
            }
          }
        }
      }
    }

    return ans;
  }
};

// T: O(n² · m)  S: O(n + m)
class better {
private:
  bool helper(unordered_map<char, int> &hash1,
              unordered_map<char, int> &hash2) {
    for (auto &[a, b] : hash2) {
      if (hash1[a] < b) {
        return false;
      }
    }

    return true;
  }

public:
  string minWindow(string s, string t) {
    if (s.size() < t.size()) {
      return "";
    }

    int n = s.size(), m = t.size();
    unordered_map<char, int> hash2;

    for (auto it : t) {
      hash2[it]++;
    }

    string ans;
    int min = INT_MAX;
    for (int i = 0; i < n; i++) {
      unordered_map<char, int> hash1;
      for (int j = i; j < n; j++) {
        hash1[s[j]]++;

        if (j - i + 1 > min) {
          break;
        }

        if (helper(hash1, hash2)) {
          if (j - i + 1 < min) {
            min = j - i + 1;
            ans.clear();

            for (int k = i; k <= j; k++) {
              ans.push_back(s[k]);
            }
          }
        }
      }
    }

    return ans;
  }
};

// T: O(n · m)  S: O(m)
class optimal {
private:
  bool helper(unordered_map<char, int> &hash1,
              unordered_map<char, int> &hash2) {
    for (auto &[a, b] : hash2) {
      if (hash1[a] < b) {
        return false;
      }
    }

    return true;
  }

public:
  string minWindow(string s, string t) {
    int n = s.size(), m = t.size();
    int l = 0, r = 0;
    unordered_map<char, int> hash1, hash2;

    for (auto it : t) {
      hash2[it]++;
    }

    int start = 0;
    int min = INT_MAX;
    while (r < n) {
      hash1[s[r]]++;

      while (helper(hash1, hash2)) {
        if (r - l + 1 < min) {
          min = r - l + 1;
          start = l;
        }

        hash1[s[l]]--;
        if (hash1[s[l]] == 0) {
          hash1.erase(s[l]);
        }
        l++;
      }

      r++;
    }

    if (min == INT_MAX)
      return "";

    string ans;
    for (int i = start; i < start + min; i++) {
      ans.push_back(s[i]);
    }

    return ans;
  }
};
