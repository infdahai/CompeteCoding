#include <bits/stdc++.h>
int m[20], n;
int sum;
int main() {

  for (int i = 0; i < 10; i++) {
    scanf("%d", &m[i]);
  }
  scanf("%d", &n);
  for (int i = 0; i < 10; i++) {
    if (m[i] <= n + 30)
      sum += 1;
  }

  printf("%d", sum);
  return 0;
}