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
#define vec std::vector
using ll = long long;

int main() {
  fast_io;

  string s;
  getline(cin, s);

  int t;
  cin >> t;

  vec<int> e;
  while (s.find(" ") != string::npos) {
    int found = s.find(" ");
    e.push_back(stoi(s.substr(0, found)));
    s = s.substr(found + 1);
  }
  e.push_back(stoi(s));

  vec<int> d = vec<int>(3, 0);
  for (int i = 0; i < t; i++) {
    d[e[i]]++;
  }

  int max_size = max(max(max(d[0], d[1]), d[2]), max_size);
  for (int i = t; i < e.size(); i++) {
    d[e[i - t]]--;
    d[e[i]]++;
    max_size = max(max(max(d[0], d[1]), d[2]), max_size);
  }

  cout << max_size << endl;
  return 0;
}