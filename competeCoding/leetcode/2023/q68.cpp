#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << "[debug]" #x << "=" << x << endl;
#define fast_io            \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0)
#define rep(i, a, b, c) for (int i = (a); i <= (b); i += (c))
#define per(i, a, b, c) for (int i = (a); i >= (b); i -= (c))
#define endl "\n"
#define mp make_pair
#define pb push_back
#define vec std::vector
using ll = long long;
#define INF 0x3f3f3f3f

vec<string> split_str(string is) {
  vec<string> v;
  while (is.find(" ") != string::npos) {
    int found = is.find(" ");
    v.push_back(is.substr(0, found));
    is = is.substr(found + 1);
  }
  v.push_back(is);
  return v;
}

vec<int> split(string is) {
  vec<int> v;
  while (is.find(" ") != string::npos) {
    int found = is.find(" ");
    v.push_back(stoi(is.substr(0, found)));
    is = is.substr(found + 1);
  }
  v.push_back(stoi(is));
  return v;
}

int main() {
  fast_io;

  int sn, vn;
  cin >> sn >> vn;

  vec<int> ef;
  rep(i, 1, sn, 1) {
    int a;
    cin >> a;
    ef.pb(a);
  }

  vec<int> rf;
  rep(i, 1, sn, 1) {
    int eff = ef[i - 1] * 0.1;
    rf.pb(eff);
  }
  vec<vec<int>> dp(sn + 1, vec<int>(vn + 1, 0));
  int cnt = 0;
  rep(i, 1, sn, 1) {
    cnt += (ef[i - 1] - 2 * rf[i - 1]);
    dp[i][0] = cnt;
  }

  rep(i, 1, sn, 1) {
    rep(j, 1, vn, 1) {
      dp[i][j] = max(dp[i - 1][j] + ef[i - 1] - 2 * rf[i - 1], dp[i - 1][j - 1] + ef[i - 1]);
      dp[i][j] = max(dp[i][j], j >= 2 ? dp[i - 1][j - 2] + ef[i - 1] + rf[i - 1] : 0);
      dp[i][j] = max(dp[i][j], j >= 3 ? dp[i - 3][j - 3] + ef[i - 1] + 2 * rf[i - 1] : 0);
      dp[i][j] = max(dp[i][j], j >= 4 ? dp[i - 1][j - 4] + ef[i - 1] + 3 * rf[i - 1] : 0);
    }
  }

  cout << dp[sn][vn];
  return 0;
}