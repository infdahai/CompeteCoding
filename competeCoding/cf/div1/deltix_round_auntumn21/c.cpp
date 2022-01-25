#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << "[debug]" #x << "=" << x << endl;
#define fast_io                                                                \
  ios::sync_with_stdio(0);                                                     \
  cin.tie(0);                                                                  \
  cout.tie(0)
#define rep(i, a, b, c) for (int i = (a); i <= (b); i += (c))
#define per(i, a, b, c) for (int i = (a); i >= (b); i -= (c))
#define mp make_pair
#define pb push_back
using ll = long long;
const int N = 2e5 + 5;
const int M = 1e6 + 5;
int a[N], n, e;
bool inp[M];
void init() {
  rep(i, 2, M - 1, 1) if (!inp[i]) rep(j, i + i, M - 1, i) inp[j] = 1;
}

int main() {
  fast_io;
  init();
  int tt;
  cin >> tt;
  while (tt--) {
    cin >> n >> e;
    rep(i, 0, n - 1, 1) cin >> a[i];
    vector<int> now;
    ll ans = 0;
    rep(i, 0, e - 1, 1) {
      now.clear();
      rep(j, i, n - 1, e) {
        int t;
        if (a[j] == 1)
          t = 1;
        else if (inp[a[j]])
          t = 0;
        else
          t = 2;
        now.pb(t);
      }
      // cout << "\nnow:";
      // for (auto it : now) {
      //   cout << it << " ";
      // }
      // cout << "\n";
      int d = 0, l, r;
      while (d < (int)now.size()) {
        if (now[d] < 2) {
          d++;
          continue;
        } else {
          l = 1, r = 1;
          while (d - l >= 0 && now[d - l] == 1)
            l++;
          while (d + r < (int)now.size() && now[d + r] == 1)
            r++;
          ans += 1ll * l * r - 1;
          // (l+1)(r+1)-1 => l*r - 1
          d += r;
        }
      }
    }
    cout << ans << "\n";
  }

  return 0;
}