#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 5;
const ll inf = 1e12;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)

int phi[N];
void totient() {
  rep(i, 1, N - 1) phi[i] = i;
  rep(i, 2, N - 1) if (phi[i] == i) {
    for (int j = 1; j < N; j += i)
      phi[j] -= phi[j] / i;
  }
}
ll a[N];
ll c(int l, int r) {
  if (l > r)
    return inf;
  ll ans = 0;
  for (int i = l, la; i <= r; i = la + 1) {
    la = r / (r / i);
    int x = 0;
    if (i >= l)
      x = la - i + 1;
    else if (la >= l)
      x = la - l + 1;
    ans += a[r / i] * x;
  }
  return ans;
}

ll dp[N][17];
void yo(int i, int l, int r, int optl, int optr) {
  if (l > r)
    return;
  int mid = l + (r - l) / 2;
  dp[mid][i] = inf;
  int opt = optl;
  ll cost = c(min(mid, optr) + 1, mid);
  for (int k = min(mid, optr); k >= optl; k--) {
    ll cc = dp[k][i - 1] + cost;
    if (cc <= dp[mid][i]) {
      dp[mid][i] = cc;
      opt = k;
    }
    if (k <= mid) {
      if (cost == inf)
        cost = a[mid / k];
      else
        cost += a[mid / k];
    }
  }
  yo(i, l, mid - 1, optl, opt);
  yo(i, mid + 1, r, opt, optr);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  rep(i, 1, N - 1) a[i] = a[i - 1] + phi[i];
  int n = 100000;
  dp[0][0] = 0;
  rep(i, 1, n) dp[i][0] = inf;
  for (int i = 1; i <= n; i++)
    dp[i][1] = 1LL * i * (i + 1) / 2;
  for (int i = 2; i <= 16; i++)
    yo(i, 1, n, 1, n);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    if (k >= 20 or (1 << k) > n) {
      cout << n << '\n';
    } else {
      cout << dp[n][k] << '\n';
    }
  }

  return 0;
}