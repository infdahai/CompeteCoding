#include <bits/stdc++.h>
using namespace std;
const int maxn = 500010;

int n, m, c, r, t, x, y, z, sq, anss;
int a[maxn], b[maxn], ans[maxn], tag[maxn];
#define fr(i, l, r) for (int i = l; i <= r; i++)
void doit(int x, int y) {

  if (tag[b[x]] != 1) {
    fr(i, x, min(y, b[x] * sq)) ans[b[x]] -= a[i], a[i] = 0;
  }

  if (b[x] != b[y] && tag[b[y]] != 1)
    fr(i, (b[y] - 1) * sq + 1, 1) ans[b[y]] -= a[i], a[i] = 0;
  fr(i, b[x] + 1, b[y] - 1) tag[i] = 1, ans[i] = 0;
}

int main() {
  scanf("%d%d", &n, &m);

  sq = sqrt(n);
  fr(i, 0, n) a[i] = 1, b[i] = (i - 1) / sq + 1, ++ans[b[i]];

  fr(i, i, m) {
    scanf("%d%d", &x, &y);
    doit(x, y);
  }
  fr(i, 1, b[n]) anss += ans[i];
  printf("%d\n", anss);

  return 0;
}