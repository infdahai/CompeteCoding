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
  int findShortestCycle(int n, vector<vector<int>>& edges) {
    vector<int> e[n];
    for (auto& edge : edges) {
      e[edge[0]].push_back(edge[1]);
      e[edge[1]].push_back(edge[0]);
    }

    const int inf = 1e9;
    auto bfs = [&](int s, int t) -> int {
      queue<int> q;
      int dis[n];
      memset(dis, -1, sizeof(dis));
      q.push(s);
      dis[s] = 0;

      while (!q.empty()) {
        int sn = q.front();
        q.pop();

        for (int fn : e[sn]) {
          if (dis[fn] == -1) {
            if (sn == s && fn == t) continue;
            q.push(fn);
            dis[fn] = dis[sn] + 1;
          }
        }
      }

      return dis[t] == -1 ? inf : dis[t];
    };

    int ans = inf;
    for (int i = 0; i < n; i++)
      for (int j : e[i]) {
        ans = min(ans, bfs(i, j) + 1);
      }

    return ans == inf ? -1 : ans;
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