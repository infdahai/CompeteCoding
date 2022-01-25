#include <bits/stdc++.h>
using namespace std;
#define _rep(i, a, b) for (int i = (a); i <= (b); i++)
int x, n;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    bool ok = true;
    cin >> n;
    _rep(i, 1, n) {
      cin >> x;
      bool flag = false;
      for (int j = i + 1; j >= 2; j--) {
        if (x % j) {
          flag = true;
          break;
        }
      }
      ok &= flag;
    }
    if (ok)
      cout << "YES\n";
    else
      cout << "NO\n";
  }

  return 0;
}