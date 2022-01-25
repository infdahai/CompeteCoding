#include <bits/stdc++.h>

int a[101];
int i, j;
using namespace std;
int main() {
  while (~scanf("%d", &j)) {
    a[i++] = j;
  }
  for (int k = i - 2; k >= 0; k--) {
    printf("%d ", a[k]);
  }
  return 0;
}