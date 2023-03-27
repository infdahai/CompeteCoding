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

int main() {
  fast_io;

  int m, n;
  cin >> m >> n;

  vector<pair<int, int>> v;
  rep(i, 1, n, 1) {
    int a, b;
    cin >> a >> b;
    v.push_back({a, b});
  }

  int res = 0;
  for (int i = 0; i < (1 << m); i++) {
    bool f = true;
    for (auto& k : v) {
      bool t = ((i >> (m - k.first)) & 1) && ((i >> (m - k.second)) & 1);
      if (t) {
        f = false;
        break;
      }
    }
    if (f) {
      res++;
    }
  }
  cout << res << endl;

  return 0;
}