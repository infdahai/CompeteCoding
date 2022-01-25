#include <bits/stdc++.h>

int n;
int i, j;
int x;
int l = 1, r;
int main() {
  scanf("%d", &n);
  r = n;
  while (l < r) {
    x = l + (r - l) / 2;
    if (x * (x + 1) / 2 < n)
      l = x + 1;
    else
      r = x;
  }
  n -= l * (l - 1) / 2;
  if (l % 2)
    j = n, i = l + 1 - n;
  else
    i = n, j = l + 1 - n;
  printf("%d/%d", i, j);
  return 0;
}
