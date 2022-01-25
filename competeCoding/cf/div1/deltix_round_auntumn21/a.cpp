#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define debug(x) cout << "[debug]" #x << "=" << x << endl;
#define fast_io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (b); i >= (a); i--)
#define mp make_pair
#define pb push_back
using ll = long long;
vector<ll> a(20);
ll div(ll &ai) {
  ll k = 0;
  ll ans = ai;
  while (!(ans & 1)) {
    ans >>= 1;
    k++;
  }
  ai = ans;
  return k;
}

void power(int base, ll &aj, ll p) {
  ll a = base;
  ll ans = 1;
  while (p) {
    if (p & 1)
      ans *= a;
    a *= a;
    p >>= 1;
  }
  aj *= ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    rep(i, 0, n - 1) cin >> a[i];
    if (n == 1) {
      cout << a[0] << "\n";
      continue;
    }
    ll res = 0;
    rep(i, 0, n - 1) { res += div(a[i]); }
    sort(a.begin(), a.begin() + n);
    power(2, a[n - 1], res);
    cout << accumulate(a.begin(), a.begin() + n, 0LL) << "\n";
  }
  return 0;
}