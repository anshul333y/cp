#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int weight;
  cin >> weight;

  if (weight != 2 && weight % 2 == 0)
    cout << "YES";
  else
    cout << "NO";
}
