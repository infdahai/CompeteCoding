#include <bits/stdc++.h>
using namespace std;
int t, n, m, k;
#define _rep(i, a, b) for (int i = (a); i <= (b); i++)
void solve() {
  cin >> n >> m;
  vector<int> v;
  _rep(i, 0, n - 1) {
    _rep(j, 0, m - 1) { v.push_back(max(i, n - 1 - i) + max(j, m - 1 - j)); }
  }
  sort(v.begin(), v.end());
  for (auto elem : v)
    cout << elem << " ";
  cout << "\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}