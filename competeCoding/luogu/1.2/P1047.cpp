#include <bits/stdc++.h>

int l, m;
int u[110], v[110];
int vis[10000 + 10];
int main() {
  scanf("%d", &l);
  scanf("%d", &m);
  for (int i = 0; i < l + 1; i++) {
    vis[i] = 0;
  }
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &u[i], &v[i]);
    for (int j = u[i]; j <= v[i]; j++)
      vis[j] = 1;
  }
  int sum = 0;
  for (int i = 0; i <= l; i++) {
    if (vis[i] == 0)
      sum += 1;
  }
  printf("%d\n", sum);
  return 0;
}