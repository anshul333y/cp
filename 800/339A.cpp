#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string temp;
  cin >> temp;

  vector<int> num;
  for (auto it : temp) {
    if (it != '+') {
      num.push_back(it - '0');
    }
  }

  sort(num.begin(), num.end());

  cout << num[0];
  for (int i = 1; i < num.size(); i++) {
    cout << '+' << num[i];
  }
}
