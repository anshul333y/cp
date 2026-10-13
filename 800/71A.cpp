#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int count;
  cin >> count;

  for (int i = 0; i < count; i++) {
    string temp;
    cin >> temp;

    int n = temp.size();
    if (temp.size() > 10)
      cout << temp[0] << n - 2 << temp[n - 1];
    else
      cout << temp;

    cout << endl;
  }
}
