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

  std::vector<int> a;
  rep(i, 1, n, 1) {
    int b;
    cin >> b;
    a.push_back(b);
  }

  sort(a.begin(), a.end());
  int l = 0, r = a.size() - 1;

  int tw = a[l] + a[r];
  int res = 0;
  while (l < r) {
    if (tw > m) {
      res++;
      r--;
    } else {
      r--;
      l++;
      res++;
    }
  }
  if (l == r) {
    res++;
  }
  cout << res << endl;

  return 0;
}