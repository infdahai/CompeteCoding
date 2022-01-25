#include <bits/stdc++.h>

const int maxn = 1005;
#define fr(i, l, r) for (int i = l; i <= r; i++)
int n, m, k, t;
int a[maxn];
bool v[maxn][maxn];
int main() {
  scanf("%d%d%d", &n, &m, &k);
  fr(i, 1, n) {
    fr(j, 1, m) {
      scanf("%d", &t);
      if (!v[t][j])
        v[t][j] = true, a[t]++;
    }
  }
  fr(i, 1, k - 1) printf("%d ", a[i]);
  printf("%d", a[k]);
  return 0;
}