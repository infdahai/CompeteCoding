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

// realtime dijkstra
class Graph {
  vector<vector<int>> g;

 public:
  Graph(int n, vector<vector<int>>& edges) {
    g = vector<vector<int>>(n, vector<int>(n, INT_MAX / 2));
    for (auto& e : edges) {
      g[e[0]][e[1]] = e[2];
    }
  }

  void addEdge(vector<int> e) { g[e[0]][e[1]] = e[2]; }

  int shortestPath(int node1, int node2) {
    int n = g.size();
    vector<int> dis(n, INT_MAX / 2), vis(n);
    dis[node1] = 0;
    while (1) {
      int x = -1;
      for (int i = 0; i < n; i++) {
        if (!vis[i] && (x < 0 || dis[i] < dis[x])) x = i;
      }
      if (x < 0 || dis[x] == INT_MAX / 2) return -1;
      if (x == node2) {
        return dis[x];
      }
      vis[x] = true;
      for (int y = 0; y < n; y++) {
        dis[y] = min(dis[y], dis[x] + g[x][y]);
      }
    }
  }
};

// offline floyd
class Graph1 {
  vector<vector<int>> d;

 public:
  Graph1(int n, vector<vector<int>>& edges) {
    d = vector<vector<int>>(n, vector<int>(n, INT_MAX / 3));
    for (int i = 0; i < n; i++) d[i][i] = 0;
    for (auto& e : edges) {
      d[e[0]][e[1]] = e[2];
    }
    for (int k = 0; k < n; k++)
      for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
  }

  void addEdge(vector<int> e) {
    int x = e[0], y = e[1], w = e[2];
    int n = d.size();
    if (w >= d[x][y]) {
      return;
    }
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) {
        d[i][j] = min(d[i][j], d[i][x] + w + d[y][j]);
      }
  }

  int shortestPath(int node1, int node2) {
    int ans = d[node1][node2];
    return ans < INT_MAX / 3 ? ans : -1;
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