#include <bits/stdc++.h>

const double ga = 0.5772156649;

int main() {
  int n;
  int k;
  scanf("%d", &k);
  n = exp(k - ga) + 0.5;
  printf("%d", n);
  return 0;
}