#include <bits/stdc++.h>
using namespace std;
#define _rep(i, a, b) for (int i = (a); i <= (b); ++i)
int t, n, l;
int a[31];
int x;
int y;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> t;
  for (; t; t--) {
    cin >> n >> l;
    memset(a, 0, sizeof(a));
    _rep(i, 1, n) {
      cin >> x;
      int j = 0;
      while (x) {
        if (x & 1) {
          a[j] += 1;
        }
        x >>= 1;
        j++;
      }
    }
    y = 0;
    _rep(i, 0, l - 1) {
      if (a[i] > n - a[i])
        y |= 1 << i;
    }
    cout << y << "\n";
  }
}