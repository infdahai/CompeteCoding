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
const int N = 1e3 + 5;
int n, d;
int x[N], y[N];
int sz[N], fa[N];
int v, vis[N];
vector<int> vt;
int find(int now) { return fa[now] == now ? now : fa[now] = find(fa[now]); }
int main() {
  fast_io;
  cin >> n >> d;
  rep(i, 1, d, 1) cin >> x[i] >> y[i];
  rep(i, 1, n, 1) fa[i] = i, sz[i] = 1;

  rep(i, 1, d, 1) {
    int xrt = find(x[i]), yrt = find(y[i]);
    if (xrt == yrt)
      v++;
    else {
      fa[xrt] = yrt;
      sz[yrt] += sz[xrt];
    }
    fill(vis + 1, vis + n + 1, 0);
    vt.clear();
    rep(j, 1, n, 1) {
      int rt = find(j);
      if (vis[rt])
        continue;
      vis[rt] = 1;
      vt.pb(sz[rt]);
    }
    // cout << "\n" << d << "\n";
    // rep(i, 1, n, 1) { cout << i << " [ " << fa[i] << " ] \n"; }
    // cout << "\n";
    auto cmp = [](int a, int b) { return a > b; };
    sort(vt.begin(), vt.end(), cmp);
    int ans = 0;
    rep(i, 0, min(v + 1, (int)vt.size()) - 1, 1) ans += vt[i];
    cout << ans - 1 << '\n';
  }

  return 0;
}