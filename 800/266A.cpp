#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  string temp;
  cin >> temp;

  int ans = 0;
  for (int i = 1; i < n; i++) {
    if (temp[i] == temp[i - 1])
      ans++;
  }

  cout << ans;
}
