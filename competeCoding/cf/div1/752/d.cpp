#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (b); i >= (a); i--)
#define mp make_pair
#define pb push_back
const int N = 1e5 + 5;
using ll = long long;
int phi[N];
const ll inf = 1e12;
void totient() {
  rep(i, 1, N - 1) phi[i] = i;
  rep(i, 2, N - 1) {
    if (phi[i] == i) {
      for (int j = i; j < N; j += i)
        phi[j] -= phi[j] / i;
    }
  }
}
ll a[N], s1[N][320], s2[N][320];
int root[N];
ll c(int l, int r) {
  if (l > r)
    return inf;
  ll ans = 0;
  if (r / l <= root[r]) {
    return s1[r][r / l] - a[r / l] * (l - 1 - r / ((r / l) + 1));
  } else {
    return s2[r][l];
  }
  return ans;
}
ll dp[N][17];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  totient();
  rep(i, 1, N - 1) a[i] = a[i - 1] + phi[i];
  rep(i, 1, N - 1) {
    root[i] = 0;
    for (int j = 1; j * j <= i; j++) {
      s1[i][j] = s1[i][j - 1] + a[j] * (i / j - i / (j + 1));
      root[i] = j;
    }
    s2[i][i / (root[i] + 1) + 1] = s1[i][root[i]];
    for (int j = i / (root[i] + 1); j >= 1; j--) {
      s2[i][j] = s2[i][j + 1] + a[i / j];
    }
  }
  int n = 100000;
  dp[0][0] = 0;
  rep(i, 1, n) dp[i][0] = inf;
  for (int k = 1; (1 << k) <= n; k++) {
    dp[0][k] = 0;
    vector<pair<int, int>> v;
    v.pb(mp(0, 0));
    rep(x, 1, n) {
      int j = (--lower_bound(v.begin(), v.end(), mp(x + 1, 0)))->second;
      dp[x][k] = dp[j][k - 1] + c(j + 1, x);
      for (int i = (int)v.size() - 1; i >= 0; i--) {
        int y = v[i].first, oldj = v[i].second;
        if (y > x &&
            dp[x][k - 1] + c(x + 1, y) < dp[oldj][k - 1] + c(oldj + 1, y))
          v.pop_back();
        else {
          int l = y + 1, r = n + 1;
          while (l < r) {
            int mid = l + (r - l) / 2;
            if (dp[x][k - 1] + c(x + 1, mid) <
                dp[oldj][k - 1] + c(oldj + 1, mid))
              r = mid;
            else
              l = mid + 1;
          }
          if (r != n + 1)
            v.pb(mp(r, x));
          break;
        }
      }
      if (v.size() == 0)
        v.pb(mp(0, x));
    }
  }

  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    if (k >= 20 or (1 << k) > n) {
      cout << n << "\n";
    } else {
      cout << dp[n][k] << "\n";
    }
  }

  return 0;
}