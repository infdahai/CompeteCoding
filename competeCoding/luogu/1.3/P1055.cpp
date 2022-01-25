#include <bits/stdc++.h>

const int c = 11;
char a[15];
int r = 0;
char s[12] = "0123456789X";
int main() {
  int k = 1;
  fgets(a, 15, stdin);
  // printf("%d\n", strlen(a));
  for (int i = 0; i < 12; i++) {
    if (a[i] == '-')
      continue;
    r += k++ * (a[i] - '0');
  }
  if (s[r % c] == a[12]) {
    printf("Right");
  } else {
    a[12] = s[r % c];
    fputs(a, stdout);
  }

  return 0;
}
