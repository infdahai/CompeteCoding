#include <bits/stdc++.h>
using namespace std;
int x, y, n;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    cin >> x >> y;
    if (x > y) {
      cout << x + y << "\n";
    } else {
      cout << y - y % x / 2 << "\n";
    }
  }
  return 0;
}