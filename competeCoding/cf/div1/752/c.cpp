#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353, N = 1e5 + 9;
int n;
int a[N];
vector<int> v[2];
int dp[2][N];
using ll = long long;
ll ans;
#define _rep(i, a, b) for (int i = (a); i <= (b); i++)
void solve() {
  cin >> n;
  _rep(i, 1, n) cin >> a[i];
  ans = 0;
  for (int i = n; i > 0; i--) {
    int s = i & 1;
    v[s].push_back(a[i]);
    dp[s][a[i]] = 1;
    int la = a[i];
    for (auto x : v[s ^ 1]) {
      int times = dp[s ^ 1][x];
      int split = (a[i] + x - 1) / x;
      int k = a[i] / split;
      ans += 1LL * (split - 1) * times * i;
      dp[s][k] += times;
      if (la != k) {
        v[s].push_back(k), la = k;
      }
    }
    for (auto x : v[s ^ 1])
      dp[s ^ 1][x] = 0;
    v[s ^ 1].clear();
    ans %= mod;
  }
  cout << ans << "\n";
  for (auto x : v[0])
    dp[0][x] = 0;
  for (auto x : v[1])
    dp[1][x] = 0;
  v[0].clear();
  v[1].clear();
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}