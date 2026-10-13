#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      int temp;
      cin >> temp;
      if (temp) {
        cout << abs(2 - i) + abs(2 - j);
        return 0;
      }
    }
  }
}
