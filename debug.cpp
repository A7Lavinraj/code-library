#include <bits/stdc++.h>
using namespace std;

template<typename T1, typename T2>
ostream& operator<<(ostream &os, const pair<T1, T2> &p) {
  os << "(" << p.first << ", " << p.second << ")";
  return os;
}

template<typename T>
ostream& operator<<(ostream &os, const vector<T> &v) {
  os << "[";
  for (int i = 0; i < v.size(); i++) {
    if (i > 0) os << ", ";
    os << v[i];
  }
  os << "]";
  return os;
}

template<typename T>
ostream& operator<<(ostream &os, const set<T> &s) {
  os << "{";
  for (auto it = s.begin(); it != s.end(); ++it) {
    if (it != s.begin()) os << ", ";
    os << *it;
  }
  os << "}";
  return os;
}

template<typename K, typename V>
ostream& operator<<(ostream &os, const map<K, V> &m) {
  os << "{";
  for (auto it = m.begin(); it != m.end(); ++it) {
    if (it != m.begin()) os << ", ";
    os << it->first << ": " << it->second;
  }
  os << "}";
  return os;
}

template<typename T>
void debug_out(T val) {
  cerr << val;
}

template<typename T, typename... Args>
void debug_out(T val, Args... args) {
  cerr << val << " ";
  debug_out(args...);
}

#define dbg(...) do { cerr << "[" << #__VA_ARGS__ << "]: "; debug_out(__VA_ARGS__); cerr << endl; } while (0)

int main() {
  int x = 42;
  double y = 3.14;
  string str = "Hello";
  vector<int> vec = {1, 2, 3, 4, 5};
  pair<int, string> p = {1, "one"};
  set<int> s = {10, 20, 30};
  map<string, int> mp = {{"a", 1}, {"b", 2}, {"c", 3}};

  dbg(x);
  dbg(y, str);
  dbg(vec);
  dbg(p);
  dbg(s);
  dbg(mp);

  return 0;
}
