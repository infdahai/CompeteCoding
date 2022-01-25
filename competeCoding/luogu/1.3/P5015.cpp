#include <bits/stdc++.h>

char s[10];
int main() {
  // scanf("%s", s);
  fgets(s, 10, stdin);
  int c = strlen(s);
  int a = 0;
  for (int i = 0; i < c; i++) {
    if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') ||
        (s[i] >= '0' && s[i] <= '9'))
      a++;
  }
  printf("%d", a);
  return 0;
}