#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string temp;
  cin >> temp;

  map<char, int> hash;
  for (auto it : temp) {
    hash[it]++;
  }

  if (hash.size() % 2 == 0)
    cout << "CHAT WITH HER!";
  else
    cout << "IGNORE HIM!";
}
