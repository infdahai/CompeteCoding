#include <bits/stdc++.h>

int n;
int a, b;
int ans;
int k, w;
int main() {
  scanf("%d", &n);
  for (int i = 1; i < 4; i++) {
    scanf("%d%d", &a, &b);
    k = a, w = b;
    while (a < n)
      a <<= 1, b <<= 1;
    while (a > n)
      a -= k, b -= w;
    while (a < n)
      a += k, b += w;
    if (b < ans || ans == 0)
      ans = b;
  }

  printf("%d", ans);
  return 0;
}