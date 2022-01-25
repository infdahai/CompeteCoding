#include <bits/stdc++.h>

using namespace std;
int n;
int x, r;
int a[10005];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    if (a[x])
      continue;
    a[x] = 1, r++;
  }
  cout << r << "\n";
  for (int i = 1; i <= 1000; i++)
    if (a[i])
      cout << i << " ";

  return 0;
}