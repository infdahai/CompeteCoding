#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << "[debug]" #x << "=" << x << endl;
#define fast_io            \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0)
#define rep(i, a, b, c) for (int i = (a); i <= (b); i += (c))
#define per(i, a, b, c) for (int i = (a); i >= (b); i -= (c))
#define endl "\n"
#define mp make_pair
#define pb push_back
using ll = long long;

bool comp(pair<string, int>& a, pair<string, int>& b) {
  if (a.second > b.second) {
    return true;
  }
  if (a.second == b.second) {
    if (a.first.size() < b.first.size()) {
      return true;
    }
    if (a.first.size() == b.first.size()) {
      return a.first < b.first;
    }
  }
  return false;
}

int main() {
  fast_io;

  string s;
  getline(cin, s);

  vector<string> v;
  while (s.find(" ") != string::npos) {
    int found = s.find(" ");
    v.pb(s.substr(0, found));
    s = s.substr(found + 1);
  }
  v.pb(s);

  for (int i = 0; i < v.size(); i++) {
    sort(v[i].begin(), v[i].end());
  }

  map<string, int> m;
  for (int i = 0; i < v.size(); i++) {
    if (m.count(v[i])) {
      m[v[i]] += 1;
    } else {
      m[v[i]] = 1;
    }
  }

  vector<pair<string, int>> vp;
  for (auto& x : m) {
    vp.pb(x);
  }
  sort(vp.begin(), vp.end(), comp);
  for (auto it = vp.begin(); it != vp.end(); it++) {
    for (int i = 1; i <= it->second; i++) {
      cout << it->first;
      if (i == it->second && it + 1 == vp.end()) {
        continue;
      }
      cout << " ";
    }
  }

  return 0;
}