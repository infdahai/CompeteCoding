#include <bits/stdc++.h>

int a, b, d;
int m;
bool f;
int main() {
  //   bool flag;
  for (int i = 0; i < 7; i++) {
    scanf("%d%d", &a, &b);
    a = a + b;
    if (a > 8) {
      f = true;
      if (m < a)
        m = a, d = i + 1;
    }
  }
  if (!f)
    printf("0");
  else
    printf("%d", d);
  return 0;
}