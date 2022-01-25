#include <bits/stdc++.h>

using namespace std;
int f[5][5] = {{0, 0, 1, 1, 0},
               {1, 0, 0, 1, 0},
               {0, 1, 0, 0, 1},
               {0, 0, 1, 0, 1},
               {1, 1, 0, 0, 0}};
int a, b, n;
int s[205];
int t[205];
int c, d;
int main() {
  // for (int i = 0; i <= 5; i++)
  //   for (int j = 0; j < i; j++) {
  //     f[i][j] = -f[j][i];
  //   }
  cin >> n >> a >> b;
  for (int i = 0; i < a; i++)
    cin >> s[i];
  for (int j = 0; j < b; j++)
    cin >> t[j];

  for (int i = 0; i < n; i++) {
    c += f[s[i % a]][t[i % b]];
    d += f[t[i % b]][s[i % a]];
  }
  cout << c << " " << d;

  return 0;
}