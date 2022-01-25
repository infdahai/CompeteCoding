#include <bits/stdc++.h>
using namespace std;
#define _rep(i, a, b) for (int i = (a); i <= (b); ++i)
int T;
const int maxn = 150005;
int n, a[maxn];
int ha[maxn];
int res;
int main() {
  scanf("%d", &T);
  while (T--) {
    res = -1;
    scanf("%d", &n);
    memset(ha, 0, sizeof(ha));
    _rep(i, 1, n) {
      scanf("%d", &a[i]);
      if (!ha[a[i]])
        ha[a[i]] = i;
      else {
        res = max(res, n - i + ha[a[i]]);
        ha[a[i]] = i;
      }
    }
    printf("%d\n", res);
  }
  return 0;
}