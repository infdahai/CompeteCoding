#include <bits/stdc++.h>

using namespace std;

int a[10005][4];
int n, y, x, t = -1;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;

  for (int i = 1; i <= n; i++)
    cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3], a[i][2] += a[i][0],
        a[i][3] += a[i][1];

  cin >> x >> y;
  for (int i = n; i >= 1; i--) {
    if (x >= a[i][0] && x <= a[i][2] && y >= a[i][1] && y <= a[i][3]) {
      t = i;
      break;
    }
  }
  cout << t;

  return 0;
}