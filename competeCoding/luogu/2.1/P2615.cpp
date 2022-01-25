#include <bits/stdc++.h>

using namespace std;
int n;
int m[40][40];
int a, b, t;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  a = 1;
  b = n / 2 + 1;
  t = 2;
  m[a][b] = 1;
  while (t <= n * n) {
    if (a == 1 && b != n)
      a = n, b = b + 1;
    else if (b == n && a != 1)
      b = 1, a = a - 1;
    else if (a == 1 && b == n)
      a = a + 1;
    else if (!m[a - 1][b + 1])
      a = a - 1, b = b + 1;
    else
      a = a + 1;
    m[a][b] = t;
    t++;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < n; j++) {
      cout << m[i][j] << " ";
    }
    cout << m[i][n] << "\n";
  }

  return 0;
}