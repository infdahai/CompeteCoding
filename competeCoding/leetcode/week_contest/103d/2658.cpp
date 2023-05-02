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
  int findMaxFish(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    bool vis[n][m];
    memset(vis, 0, sizeof(vis));
    short dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};

    auto bfs = [&](int si, int sj) {
      using pii = pair<int, int>;
      queue<pii> q;
      q.push(pii(si, sj));
      vis[si][sj] = true;
      int ret = 0;
      while (!q.empty()) {
        pii p = q.front();
        q.pop();
        int i = p.first, j = p.second;
        ret += grid[i][j];
        for (int k = 0; k < 4; k++) {
          int di = i + dir[k][0];
          int dj = j + dir[k][1];
          if (di < 0 || di >= n || dj > 0 || dj >= m || grid[di][dj] == 0 ||
              vis[di][dj]) {
            continue;
          }
          q.push(pii(di, dj));
          vis[di][dj] = true;
        }
      }
      return ret;
    };

    int ans = 0;
    // 求每个连通块元素和的最大值
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (grid[i][j] && !vis[i][j]) ans = max(ans, bfs(i, j));
    return ans;
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