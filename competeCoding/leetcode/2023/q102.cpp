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

// #define TXT
int main() {
  fast_io;
#ifdef TXT
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif  // TXT

  int m, n;
  cin >> m >> n;

  vec<vec<int>> ma;
  rep(i, 1, m, 1) {
    vec<int> temp;
    rep(j, 1, n, 1) {
      int a;
      cin >> a;
      temp.pb(a);
    }
    ma.pb(temp);
  }

  priority_queue<int, vec<int>, ::greater<int>> pq;
  vec<vec<int>> res(m, vec<int>(n, 0));

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (pq.empty()) {
        pq.emplace(ma[i][j]);
        continue;
      }
      res[i][j] += pq.size();
      while (!pq.empty() && pq.top() <= ma[i][j]) {
        assert(j >= 1);
        pq.pop();
      }
      pq.emplace(ma[i][j]);
    }
    pq = {};
  }

  for (int j = 0; j < n; j++) {
    for (int i = 0; i < m; i++) {
      if (pq.empty()) {
        pq.emplace(ma[i][j]);
        continue;
      }
      res[i][j] += pq.size();
      while (!pq.empty() && pq.top() <= ma[i][j]) {
        assert(i >= 1);
        pq.pop();
      }
      pq.emplace(ma[i][j]);
    }
    pq = {};
  }

  cout << m << " " << n << endl;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cout << res[i][j] << " ";
    }
  }

#ifdef TXT
  fclose(stdin);
  fclose(stdout);
#endif  // TXT
  return 0;
}