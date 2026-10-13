#include <bits/stdc++.h>
using namespace std;

// ── Candy ─────────────────────────────────────────────────────

// T: O(n) S: O(n)
class brute {
public:
  int candy(vector<int> &ratings) {
    int n = ratings.size();
    vector<int> left(n), right(n);
    left[0] = 1;
    right[n - 1] = 1;

    for (int i = 1; i < n; i++) {
      if (ratings[i] > ratings[i - 1])
        left[i] = left[i - 1] + 1;
      else
        left[i] = 1;
    }

    for (int i = n - 2; i >= 0; i--) {
      if (ratings[i] > ratings[i + 1])
        right[i] = right[i + 1] + 1;
      else
        right[i] = 1;
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
      sum += max(left[i], right[i]);
    }

    return sum;
  }
};

// T: O(n) S: O(n)
class better {
public:
  int candy(vector<int> &ratings) {
    int n = ratings.size();
    vector<int> left(n);
    left[0] = 1;

    for (int i = 1; i < n; i++) {
      if (ratings[i] > ratings[i - 1])
        left[i] = left[i - 1] + 1;
      else
        left[i] = 1;
    }

    int right = 1, sum = max(left[n - 1], right);
    for (int i = n - 2; i >= 0; i--) {
      if (ratings[i] > ratings[i + 1]) {
        sum += max(left[i], right + 1);
        right++;
      } else {
        sum += max(left[i], 1);
        right = 1;
      }
    }

    return sum;
  }
};

// T: O(n) S: O(1)
class optimal {
public:
  int candy(vector<int> &ratings) {
    int n = ratings.size();

    int sum = 1, i = 1;

    while (i < n) {
      if (ratings[i] == ratings[i - 1]) {
        sum = sum + 1;
        i++;
        continue;
      }

      int peak = 1;
      while (i < n && ratings[i] > ratings[i - 1]) {
        peak += 1;
        sum += peak;
        i++;
      }

      int down = 1;
      while (i < n && ratings[i] < ratings[i - 1]) {
        sum += down;
        i++;
        down++;
      }

      if (down > peak) {
        sum += down - peak;
      }
    }

    return sum;
  }
};
