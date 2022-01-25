#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
const int N = 205;
int mod;
int power(ll n, ll k) {
  int ans = 1 % mod;
  n %= mod;
  if (n <= 0)
    n += mod;
  while (k) {
    if (k & 1)
      ans = (ll)ans * n % mod;
    n = (ll)n * n % mod;
    k >>= 1;
  }
  return ans;
}

int dp[N][N][40], fac[N], ifac[N];
int vis[N][N][40];
int n, a1;

int yo(int i, int sum, int k) {
  if (i == n)
    return fac[n];
  if (k == 0)
    return 1LL * fac[n] * ifac[n - i] % mod;
  if (vis[i][sum][k] == a1)
    return dp[i][sum][k];
  vis[i][sum][k] = a1;
  int &ans = dp[i][sum][k];
  ans = 0;
  int r = (a1 - sum) / k;
  for (int cnt = r; cnt >= 0; cnt--) {
    if (k > 1 and i + cnt < n - a1 + 1 - k + 1)
      continue;
    ans += 1LL * yo(i + cnt, sum + cnt * k, k - 1) * ifac[cnt] % mod;
    ans %= mod;
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> mod;
  fac[0] = 1;
  ifac[0] = 1;
  rep(i, 1, N - 1) {
    fac[i] = 1LL * fac[i - 1] * i % mod;
    ifac[i] = power(fac[i], mod - 2);
  }
  int ans = 0;
  int lim = 2 * sqrt(n) + 1;
  for (a1 = max(1, n - lim); a1 <= n; a1++) {
    ans += yo(0, 0, n + 1 - a1);
    ans %= mod;
  }
  ans %= mod;
  cout << ans << "\n";
  return 0;
}