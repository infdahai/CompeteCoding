#include <bits/stdc++.h>
int n, x;
int ans, j;
int main() {
  scanf("%d%d", &n, &x);
  for (int i = 1; i < n + 1; i++) {
    j = i;
    while (j != 0) {
      if (j % 10 == x)
        ans += 1;
      j /= 10;
    }
  }
  printf("%d", ans);

  return 0;
}