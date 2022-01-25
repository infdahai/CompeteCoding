#include <bits/stdc++.h>

using namespace std;
string a, b;
int c, d, e, f[27], g[27], h, k, l[100], m, n, o;
int main() {
  cin >> o;

  while (o > 0) {
    c = d = e = h = k = m = n = 0, o--;
    memset(f, 0, sizeof(f)), memset(l, 0, sizeof(l));
  }
  do {
    a = b;
    cin >> b;
  } while (b[0] != 'O');
  for (int i = 0; i < a.length(); i++)
    c = c * 10 + a[i] - '0';
  for (int i = 4; i < b.length() - 1; i++)
    d = d * 10 + b[i] - '0';
  while (c > 0) {
    c--;
    cin >> a;
    if (a[0] == 'F') {
    }
  }
  return 0;
}