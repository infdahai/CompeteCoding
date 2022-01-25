#include <bits/stdc++.h>

int n, k;
using namespace std;
int a[205][10];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> k;
  for (int i = 1; i <= n; i++)
    a[i][1] = a[i][0] = 1;
  for (int t = 2; t <= k; t++)
    a[0][t] = a[1][t] = 0;
  for (int i = 2; i <= n; i++)
    for (int j = 2; j <= k; j++)
      if (i > j)
        a[i][j] = a[i - 1][j - 1] + a[i - j][j];
      else
        a[i][j] = a[i - 1][j - 1];
  cout << a[n][k];
  return 0;
}