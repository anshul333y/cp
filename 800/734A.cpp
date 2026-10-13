#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int count;
  cin >> count;

  int antonCount = 0, danikCount = 0;
  while (count--) {
    char temp;
    cin >> temp;

    if (temp == 'A')
      antonCount++;
    else
      danikCount++;
  }

  if (antonCount > danikCount)
    cout << "Anton";
  else if (danikCount > antonCount)
    cout << "Danik";
  else
    cout << "Friendship";
}
