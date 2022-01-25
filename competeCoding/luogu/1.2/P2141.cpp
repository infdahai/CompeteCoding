#include <bits/stdc++.h>

int n;
const int m = 20005;
int a[105];
int t[m], g[m];
int ans;
int maxn;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    g[a[i]] = 1;
  }
  for (int i = 1; i < n; i++) {
    for (int j = i + 1; j <= n; j++) {
      t[a[i] + a[j]]++;
      maxn = std::max(maxn, a[i] + a[j]);
    }
  }

  for (int i = 1; i <= maxn; i++)
    if (t[i] > 0 && g[i])
      ans++;
  printf("%d\n", ans);
  return 0; //
}