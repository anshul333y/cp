#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  vector<int> temp(n);
  for (int i = 0; i < n; i++)
    cin >> temp[i];

  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (temp[i] > 0 && temp[i] >= temp[k - 1])
      ans++;
  }

  cout << ans;
}
