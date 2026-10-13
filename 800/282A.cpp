#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int count;
  cin >> count;

  int ans = 0;
  while (count--) {
    string temp;
    cin >> temp;
    if (temp == "++X" || temp == "X++")
      ans++;
    else
      ans--;
  }

  cout << ans;
}
