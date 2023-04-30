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
  int minimumCost(vector<int>& start, vector<int>& target,
                  vector<vector<int>>& specialRoads) {
    using pii = pair<int, int>;
    map<pii, int> mat;
    int sz = 0;
    auto add = [&](int x, int y) {
      auto p = mp(x, y);
      if (mat.count(p)) {
        return;
      }
      mat[p] = sz++;
    };

    add(start[0], start[1]);
    add(target[0], target[1]);
    for (auto& r : specialRoads) add(r[0], r[1]), add(r[2], r[3]);

    int n = mat.size();
    int x[n], y[n];
    for (auto& [k, v] : mat) {
      x[v] = k.first;
      y[v] = k.second;
    }

    vector<int> e[n];
    vector<ll> v[n];
    rep(i, 0, n - 1, 1) {
      rep(j, 0, n - 1, 1) {
        if (i != j) {
          e[i].pb(j);
          int val = abs(x[i] - x[j]) + abs(y[i] - y[j]);
          v[i].pb(val);
        }
      }
    }

    for (auto& r : specialRoads) {
      int xn = mat[mp(r[0], r[1])];
      int yn = mat[mp(r[2], r[3])];
      e[xn].pb(yn);
      v[xn].pb(r[4]);
    }

    int s = mat[mp(start[0], start[1])], t = mat[mp(target[0], target[1])];
    ll dis[n];
    memset(dis, -1, sizeof(dis));
    using pli = pair<ll, int>;
    priority_queue<pli> pq;
    pq.push(mp(0, s));
    // 大根堆，所以用负值
    while (!pq.empty()) {
      auto p = pq.top();
      pq.pop();
      int sn = p.second;
      ll d = -p.first;
      if (dis[sn] >= 0) continue;
      dis[sn] = d;
      for (int i = 0; i < e[sn].size(); i++) {
        int fn = e[sn][i];
        if (dis[fn] >= 0) continue;
        pq.push(pli(-d-v[sn][i],fn));
      }
    }
    return dis[t];
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