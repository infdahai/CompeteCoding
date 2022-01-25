#include <bits/stdc++.h>

int sum;
int ans;
int w;
int h;

int main() {
  for (int i = 0; i < 12; i++) {
    scanf("%d", &w);
    h += 300;
    h -= w;
    if (h < 0) {
      printf("-%d", i + 1);
      return 0;
    }
    sum += (h / 100) * 100;
    h %= 100;
  }

  ans = sum * 1.2 + h;
  printf("%d", ans);
  return 0;
}
