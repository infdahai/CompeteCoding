#include <bits/stdc++.h>

using ll = long long;
using namespace std;
ll n;
int k;
const int l = 100003;
int a[l];
int main() {
  cin >> n >> k;
  a[0] = a[1] = 1;
  // for (int i = 1; i <= n; i++)
  // for (int j = max(i - k, 0); j <= i - 1; j++)
  // a[i] += a[j] % l;
  for (int i = 2; i <= n; i++)
    if (i <= k)
      a[i] = 2 * a[i - 1] % l;
    else
      a[i] = 2 * a[i - 1] - a[i - k - 1], a[i] %= l;
  cout << (a[n] + l) % l;
  return 0;
}