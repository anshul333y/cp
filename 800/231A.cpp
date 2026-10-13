#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int count;
  cin >> count;

  int ans = 0;
  while (count--) {
    int a, b, c;
    cin >> a >> b >> c;

    if (a + b + c >= 2)
      ans++;
  }

  cout << ans;
}
