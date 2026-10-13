#include <bits/stdc++.h>
using namespace std;

int main() {

  // pairs
  pair<int, int> p = {1, 2};
  cout << p.first << " " << p.second << endl; // 1 2
  pair<int, pair<int, int>> q = {1, {2, 3}};
  cout << q.first << " " << q.second.first << " " << q.second.second
       << endl; // 1 2 3
  pair<int, int> array[] = {{1, 2}, {3, 4}};
  cout << array[0].first << " " << array[0].second << " " << array[1].first
       << " " << array[1].second << endl; // 1 2 3 4

  // vectors
  vector<int> v;
  v.push_back(1);
  v.emplace_back(2);
  vector<pair<int, int>> w;
  w.push_back({1, 2});
  w.emplace_back(3, 4);
  vector<int> x(5, 3);                              // {3, 3, 3, 3, 3}
  vector<int> y(5);                                 // {0, 0, 0, 0, 0}
  vector<int> x2(x);                                // {3, 3, 3, 3, 3}
  cout << v[0] << " " << v[1] << endl;              // 1 2
  cout << w[0].first << " " << w[1].second << endl; // 1 4
  for (vector<int>::iterator i = x.begin(); i != x.end(); i++)
    cout << *i << " "; // 3 3 3 3 3
  cout << endl;
  for (auto i = y.begin(); i != y.end(); i++)
    cout << *i << " "; // 0 0 0 0 0
  cout << endl;
  for (auto i : x2)
    cout << i << " "; // 3 3 3 3 3
  cout << endl;
  vector<int> e;
  e.emplace_back(10);
  e.emplace_back(20);
  e.emplace_back(30);
  e.emplace_back(40);
  e.emplace_back(50);
  e.emplace_back(60);
  e.erase(e.begin() + 1);
  e.erase(e.begin() + 2, e.begin() + 4);
  for (auto i : e)
    cout << i << " "; // 10 30 60
  cout << endl;
  vector<int> i(2, 100);
  i.insert(i.begin(), 300);
  i.insert(i.begin() + 2, 2, 40);
  vector<int> copy(2, 50);
  i.insert(i.begin(), copy.begin(), copy.end());
  for (auto j : i)
    cout << j << " "; // 50 50 300 100 40 40 100
  cout << endl;
  cout << i.size() << endl; // 7
  i.pop_back();
  copy.swap(i);
  for (auto j : copy)
    cout << j << " "; // 50 50 300 100 40 40
  cout << endl;
  for (auto j : i)
    cout << j << " "; // 50 50
  cout << endl;
  i.clear();
  cout << i.empty() << endl; // 1

  // list
  list<int> ls;
  ls.push_back(1);
  ls.emplace_back(2);
  ls.push_front(3);
  ls.emplace_front(4);
  for (auto i : ls)
    cout << i << " "; // 4 3 1 2
  cout << endl;

  // deque
  deque<int> dq; // same as vetor & list

  // stack
  stack<int> sk;
  sk.push(1);
  sk.push(2);
  sk.push(3);
  sk.emplace(4);
  sk.emplace(5);
  cout << sk.top() << endl; // 5
  sk.pop();
  cout << sk.top() << endl; // 4
  sk.pop();
  cout << sk.size() << endl;  // 3
  cout << sk.empty() << endl; // 0

  // queue
  queue<int> qe;
  qe.push(1);
  qe.push(2);
  qe.emplace(3);
  qe.back() += 6;
  cout << qe.back() << endl;  // 9
  cout << qe.front() << endl; // 1
  qe.pop();
  cout << qe.front() << endl; // 2

  // priority queue
  priority_queue<int> pq;
  pq.push(5);
  pq.push(1);
  pq.push(3);
  pq.emplace(4);
  pq.emplace(2);
  cout << pq.top() << endl; // 5
  pq.pop();
  cout << pq.top() << endl;                           // 4
  priority_queue<int, vector<int>, greater<int>> pqm; // minimum heap
  pqm.push(5);
  pqm.push(1);
  pqm.push(3);
  pqm.emplace(4);
  pqm.emplace(2);
  cout << pqm.top() << endl; // 1
  pqm.pop();
  cout << pqm.top() << endl; // 2

  // set - sorted & unique
  set<int> s;
  s.insert(5);
  s.insert(3);
  s.insert(3);
  s.emplace(1);
  s.emplace(4);
  s.emplace(2);
  cout << s.count(3) << endl; // 1
  auto it = s.find(3);
  s.erase(it);
  for (auto i : s)
    cout << i << " "; // 1 2 4 5
  cout << endl;

  // multiset - same as set but doesn't follow unique
  multiset<int> ms;

  // unorderedset - same as set but doesn't follow sorted
  unordered_set<int> us;

  // map - key & value. key is unique & stored in sorted order
  map<int, int> mpp1;
  map<int, pair<int, int>> mpp2;
  map<pair<int, int>, int> mpp3;
  mpp1[1] = 2;
  mpp1.insert({3, 1});
  mpp1.emplace(2, 4);
  for (auto i : mpp1)
    cout << i.first << " " << i.second << endl; // 1 2 2 4 3 1
  auto iter = mpp1.find(3);
  cout << (*iter).second << endl;

  return 0;
}
