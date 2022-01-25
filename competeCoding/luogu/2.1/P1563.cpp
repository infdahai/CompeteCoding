#include <bits/stdc++.h>

using namespace std;
struct ndoe {
  int h;
  string name;
} a[100005];

int n, m;
int x, y;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i].h >> a[i].name;
  }
  int r = 0;
  for (int j = 1; j <= m; j++) {
    cin >> x >> y;
    if (a[r].h == 0 && x == 0)
      r = (r + n - y) % n;
    else if (a[r].h == 0 && x == 1)
      r = (r + y) % n;
    else if (a[r].h == 1 && x == 0)
      r = (r + y) % n;
    else if (a[r].h == 1 && x == 1)
      r = (r + n - y) % n;
  }

  cout << a[r].name;

  return 0;
}