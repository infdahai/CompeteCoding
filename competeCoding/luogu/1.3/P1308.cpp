
#include <bits/stdc++.h>
using namespace std;
string a, b;

int main() {
  getline(cin, a);
  getline(cin, b);
  int lena = a.size();
  int lenb = b.size();

  for (int i = 0; i < lena; i++)
    a[i] = toupper(a[i]);
  for (int j = 0; j < lenb; j++)
    b[j] = toupper(b[j]);
  int res = 0; //
  int k = 0;
  for (int i = 0; i <= lenb - lena; i++) {
    int j = 0;
    for (; j < lena; j++) {
      if (a[j] != b[j + i])
        break;
      if (i > 0 && b[i - 1] != ' ')
        break;
    }
    if (j == lena && (b[j + i] == ' ' || i + j == lenb)) {
      if (++res == 1)
        k = i;
    }
  }
  if (!res)
    printf("-1");
  else {
    printf("%d %d", res, k);
  }
  return 0;
}