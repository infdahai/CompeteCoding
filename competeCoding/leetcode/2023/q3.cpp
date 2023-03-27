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

int min_res = INT_MAX;

int comp(int m0, int n0, int x, int m1, int n1, int times) {
  if (x >= m0 + n0) {
    times += 1;
    min_res = min(min_res, times);
    return times + 1;
  }

  for (int i = 0; i <= m0 && i <= x; i++) {
    for (int j = 0; j <= n0 && i + j <= x; j++) {
      if (i + j == 0) {
        continue;
      }
      bool f1 = (m0 - i == 0) || (m0 - i > n0 - j);
      bool f2 = (m1 + i == 0) || (m1 + i > n1 + j);
      if (f1 && f2) {
        int res = comp(m0 - i, n0 - j, x, m1 + i, n1 + j, times + 1);
        if (min_res > res && res != 0) {
          min_res = res;
        }
      }
    }
  }

  return 0;
}

int main() {
  fast_io;

  int m, n, x;
  scanf("%d%d%d", &m, &n, &x);

  comp(m, n, x, 0, 0, 0);

  if (min_res == INT_MAX) {
    cout << 0;
  } else {
    cout << min_res;
  }

  return 0;
}