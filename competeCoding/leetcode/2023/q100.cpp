#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << "[debug]" #x << "=" << x << endl;
#define fast_io            \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0)
#define rep(i, a, b, c) for (int i = (a); i <= (b); i += (c))
#define per(i, a, b, c) for (int i = (a); i >= (b); i -= (c))
// #define endl "\n"
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

class UF {
 public:
  vec<int> item;
  int cnt;
  UF(int n) : cnt(n) {
    item = vec<int>(n + 1, 0);
    for (int i = 0; i < n; i++) item[i] = i;
  }

  int find(int x) {
    if (x != item[x]) {
      return (item[x] = find(item[x]));
    }
    return x;
  }

  void union_connect(int x, int y) {
    int xitem = find(x);
    int yitem = find(y);
    if (xitem != yitem) {
      item[yitem] = xitem;
      cnt--;
    }
  }
};

int n;
int dfs(vec<vec<int>> &ma, int k, vec<int> &dp) {
  int time = 0;
  for (int i = 0; i < n; i++) {
    if (i != k && ma[k][i] != 0) {
      if (dp[i + 1] > 0) {
        time = max(time, dp[i + 1]);
      } else {
        time = max(time, dfs(ma, i, dp));
      }
    }
    dp[k + 1] = time + ma[k][k];
  }
  return ma[k][k] + time;
}

// #define TXT
int main() {
  fast_io;
#ifdef TXT
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif  // TXT

  cin >> n;
  vec<vec<int>> ma;
  for (int i = 0; i < n; i++) {
    vec<int> t;
    for (int j = 0; j < n; j++) {
      int a;
      cin >> a;
      t.pb(a);
    }
    ma.pb(t);
  }

  int k;
  cin >> k;
  vec<int> dp(n + 1, 0);
  cout << dfs(ma, k - 1, dp);

#ifdef TXT
  fclose(stdin);
  fclose(stdout);
#endif  // TXT
  return 0;
}