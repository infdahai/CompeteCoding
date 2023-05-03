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
#define vec vector
using ll = long long;
#define INF 0x3f3f3f3f

inline int gcd(int a, int b) { return b > 0 ? gcd(b, a % b) : a; }

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

struct lnode {
  int v;
  int next;
  lnode(int v, int next) : v(v), next(next) {}
};

// inputs.erase(remove(inputs.begin(), inputs.end(), '['), inputs.end());

class Solution {
 public:
  int minimumTotalPrice1(int n, vector<vector<int>>& edges, vector<int>& price,
                         vector<vector<int>>& trips) {
    vector<vector<int>> g(n);
    for (auto& e : edges) {
      int x = e[0], y = e[1];
      g[x].push_back(y);
      g[y].push_back(x);
    }

    int cnt[n];
    memset(cnt, 0, sizeof(cnt));
    for (auto& t : trips) {
      int end = t[1];
      function<bool(int, int)> dfs = [&](int x, int fa) {
        if (x == end) {
          cnt[x]++;
          return true;
        }
        for (int y : g[x]) {
          if (y != fa && dfs(y, x)) {
            ++cnt[x];
            return true;
          }
        }
        return false;
      };
      dfs(t[0], -1);
    }

    function<pair<int, int>(int, int)> dfs = [&](int x,
                                                 int fa) -> pair<int, int> {
      int noth = price[x] * cnt[x];
      int hal = noth / 2;
      for (int y : g[x]) {
        if (y != fa) {
          auto [nh, h] = dfs(y, x);
          noth += min(nh, h);
          hal += nh;
        }
      }
      return {noth, hal};
    };
    auto [nh, h] = dfs(0, -1);
    return min(nh, h);
  }

  int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price,
                        vector<vector<int>>& trips) {
    vector<vector<int>> g(n);
    for (auto& e : edges) {
      int x = e[0], y = e[1];
      g[x].push_back(y);
      g[y].push_back(x);
    }

    vector<vector<int>> qs(n);
    for (auto& t : trips) {
      int x = t[0], y = t[1];
      qs[x].push_back(y);
      if (x != y) {
        qs[y].push_back(x);
      }
    }

    int pa[n];
    iota(pa, pa + n, 0);
    function<int(int)> find = [&](int x) -> int {
      return pa[x] == x ? x : pa[x] = find(pa[x]);
    };

    int diff[n], father[n], color[n];
    memset(diff, 0, sizeof(diff));
    memset(father, 0, sizeof(father));
    memset(color, 0, sizeof(color));

    function<void(int, int)> tarjan = [&](int x, int fa) {
      father[x] = fa;
      color[x] = 1;
      for (int y : g[x])
        if (color[y] == 0) {
          tarjan(y, x);
          pa[y] = x;
        }
      for (int y : qs[x]) {
        if (y == x || color[y] == 2) {
          ++diff[x];
          ++diff[y];
          int lca = find(y);
          --diff[lca];
          int f = father[lca];
          if (f >= 0) {
            --diff[f];
          }
        }
      }
      color[x] = 2;
    };

    tarjan(0, -1);

    function<tuple<int, int, int>(int, int)> dfs =
        [&](int x, int fa) -> tuple<int, int, int> {
      int noh = 0, hal = 0, cnt = diff[x];
      for (int y : g[x]) {
        if (y != fa) {
          auto [nh, h, c] = dfs(y, x);
          noh += min(nh, h);
          hal += nh;
          cnt += c;
        }
      }
      noh += price[x] * cnt;
      hal += price[x] * cnt / 2;
      return {noh, hal, cnt};
    };

    auto [nh, h, _] = dfs(0, -1);
    return min(nh, h);
  }
};

// #define TXT
int main() {
  fast_io;
#ifdef TXT
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif  // TXT

#ifdef TXT
  fclose(stdin);
  fclose(stdout);
#endif  // TXT
  return 0;
}