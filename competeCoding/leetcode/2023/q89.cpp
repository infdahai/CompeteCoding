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

int t, c, m, n;
vec<string> ma;
vec<vec<int>> dirs = {{1, 0, 1}, {-1, 0, 2}, {0, 1, 3}, {0, -1, 4}};

bool dfs(vec<vec<bool>> &vis, int x, int y, int ut, int uc, int last_dir) {
  if ('T' == ma[x][y]) {
    return true;
  }
  vis[x][y] = true;

  for (auto dir : dirs) {
    int d = dir[2];
    int tx = x + dir[0];
    int ty = y + dir[1];
    bool turn_flag = false;
    bool break_flag = false;
    if (tx >= 0 && tx < n && ty >= 0 && ty <= m && !vis[tx][ty]) {
      if (last_dir != 0 && last_dir != d) {
        if (ut + 1 > t) {
          continue;
        }
        turn_flag = true;
      }
      if ('*' == ma[tx][ty]) {
        if (uc + 1 > c) {
          continue;
        }
        break_flag = true;
      }
      if (dfs(vis, tx, ty, ut + (turn_flag ? 1 : 0), uc + (break_flag ? 1 : 0), d)) {
        return true;
      }
    }
  }
  return false;
}

// #define TXT
int main() {
  fast_io;
#ifdef TXT
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif  // TXT

  string inputs;
  getline(cin, inputs);
  {
    vec<int> params = split(inputs);
    t = params[0];
    c = params[1];
  }
  getline(cin, inputs);
  {
    vec<int> params = split(inputs);
    n = params[0];
    m = params[1];
  }

  for (int i = 0; i < n; i++) {
    getline(cin, inputs);
    ma.pb(inputs);
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      vec<vec<bool>> vis(n, vec<bool>(m, false));
      if (ma[i][j] == 'S') {
        if (dfs(vis, i, j, 0, 0, 0)) {
          cout << "YES" << endl;
          return 0;
        } else {
          cout << "NO";
          return 0;
        }
      }
    }
  }

#ifdef TXT
  fclose(stdin);
  fclose(stdout);
#endif  // TXT
  return 0;
}