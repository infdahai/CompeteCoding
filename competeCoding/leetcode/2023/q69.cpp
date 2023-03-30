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

  int m, n;
  cin >> m >> n;
  vec<int> ma;
  for (int i = 0; i < m * n; i++) {
    int a;
    cin >> a;
    ma.pb(a);
  }

  int ti, tj;
  cin >> ti >> tj;

  queue<pair<int, int>> q;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (ma[i * n + j] > 0) {
        q.push(mp(i, j));
        break;
      }
    }
  }

  vec<vec<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

  while (!q.empty()) {
    auto [i, j] = q.front();
    if (ma[i * n + j] == 1) {
      break;
    }

    for (auto dir : dirs) {
      int nx = dir[0] + i, ny = dir[1] + j;
      if (nx >= 0 && nx < m && ny >= 0 && ny < m) {
        if (ma[nx * n + ny] == 0) {
          ma[nx * n + ny] = ma[i * n + j] - 1;
          q.push(mp(nx, ny));
        }
      }
    }
    q.pop();
  }

  cout << ma[ti * n + tj];

  return 0;
}