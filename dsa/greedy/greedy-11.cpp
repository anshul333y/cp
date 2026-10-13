#include <bits/stdc++.h>
using namespace std;

// ── Valid Parenthesis String ─────────────────────────────────

// T: O(3^n) exponential  S: O(n) recursion stack
class brute {
private:
  bool rec(string &s, int idx, int n, int count) {
    if (count < 0)
      return false;
    if (idx == n)
      return count == 0;

    if (s[idx] == '(')
      return rec(s, idx + 1, n, count + 1);
    if (s[idx] == ')')
      return rec(s, idx + 1, n, count - 1);

    return rec(s, idx + 1, n, count + 1) || rec(s, idx + 1, n, count - 1) ||
           rec(s, idx + 1, n, count);
  }

public:
  bool checkValidString(string s) {
    int n = s.size();

    return rec(s, 0, n, 0);
  }
};

// T: O(n) S: O(1)
class optimal {
public:
  bool checkValidString(string s) {
    int mini = 0, maxi = 0;

    for (auto it : s) {
      if (it == '(') {
        mini++;
        maxi++;
      } else if (it == ')') {
        mini--;
        maxi--;
      } else {
        mini--;
        maxi++;
      }
      if (mini < 0)
        mini = 0;
      if (maxi < 0)
        return false;
    }

    return mini == 0;
  }
};
