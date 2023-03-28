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
  vec<string> a;
  while (s.find(" ") != string::npos) {
    int found = s.find(" ");
    a.push_back(s.substr(0, found));
    s = s.substr(found + 1);
  }
  a.push_back(s);

  string ts{};
  set<string> ss;
  for (auto& x : a) {
    ss.insert(x);
  }

  for (auto b : ss) {
    bool f = true;
    for (int i = 1; i < b.length(); i++) {
      string t = b.substr(0, i);
      if (ss.count(t) == 0) {
        f = false;
        break;
      }
    }
    if (f) {
      if (b.size() > ts.size()) {
        ts = b;
      } else if (b.size() == ts.size()) {
        if (b > ts) {
          ts = b;
        }
      }
    }
  }
  cout << ts;

  return 0;
}