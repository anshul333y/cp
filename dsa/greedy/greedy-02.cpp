#include <bits/stdc++.h>
using namespace std;

// ── Lemonade Change ──────────────────────────────────────────

// T: O(n) S: O(1)
class Solution {
public:
  bool lemonadeChange(vector<int> &bills) {
    int five = 0, ten = 0, twenty = 0;

    for (auto it : bills) {
      if (it == 5) {
        five++;
      } else if (it == 10) {
        if (five >= 1) {
          ten++;
          five--;
        } else {
          return false;
        }
      } else {
        if (five && ten) {
          twenty++;
          five--;
          ten--;
        } else if (five >= 3) {
          five -= 3;
        } else {
          return false;
        }
      }
    }

    return true;
  }
};
