#include <bits/stdc++.h>
using namespace std;
int s[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int a, b;
int res, k, t;
int main() {
  scanf("%d%d", &a, &b);
  for (int i = 1; i <= 12; i++) {
    for (int j = 1; j <= s[i]; j++) {
      k = (j % 10) * 1000 + (j / 10) * 100 + (i % 10) * 10 + i / 10;
      t = k * 10000 + i * 100 + j;
      if (t < a || t > b)
        continue;
      res++;
    }
  }

  printf("%d", res);

  return 0;
}
