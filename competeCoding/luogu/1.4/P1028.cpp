
#include <bits/stdc++.h>
using ll = long long;
ll n, cnt;
ll r[1005];
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i / 2; j++)
      r[i] += r[j];
    r[i]++;
  }

  cout << r[n];
  return 0;
}