#include <bits/stdc++.h>
using namespace std;
#define _rep(i, a, b) for (int i = (a); i <= (b); i++)
const int maxi = 0x3f3f3f3f;
const int maxn = 505;
int n, l, k;
int d[maxn], a[maxn], f[maxn][maxn];
int res = maxi;
int main() {
  scanf("%d%d%d", &n, &l, &k);
  _rep(i, 0, n - 1) { scanf("%d", &d[i]); }
  d[n] = l;
  _rep(i, 0, n - 1) { scanf("%d", &a[i]); }
  memset(f, maxi, sizeof(f));
  f[0][0] = 0;
  _rep(i, 1, n) { f[i][0] = f[i - 1][0] + a[i - 1] * (d[i] - d[i - 1]); }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= i - 1; j++) {
      for (int p = k; p >= i - j - 1; p--) {
        f[i][p] = min(f[i][p], f[j][p - (i - j - 1)] + a[j] * (d[i] - d[j]));
      }
    }
  }
  _rep(i, 0, k) res = min(res, f[n][i]);
  printf("%d", res);
  return 0;
}
