#include <bits/stdc++.h>
using ll = long long;
ll n;
ll an;
bool f;
int main() {
  scanf("%lld", &n);

  f = (n < 0) ? true : false;
  n = f ? -n : n;
  while (n) {
    an *= 10;
    an += n % 10;
    n /= 10;
  }

  if (f)
    printf("-");
  printf("%lld", an);

  return 0;
}