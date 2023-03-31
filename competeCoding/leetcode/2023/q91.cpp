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

bool comp(vec<int> &x, vec<int> &y) { return x[2] < y[2]; }

// #define TXT
int main() {
  fast_io;
#ifdef TXT
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif  // TXT

  int n, a, b;
  cin >> n >> a >> b;
  vec<vec<int>> city1;
  for (int i = 0; i < a; i++) {
    int d, e, f;
    cin >> d >> e >> f;
    vec<int> temp;
    temp.pb(d);
    temp.pb(e);
    temp.pb(f);
    city1.push_back(temp);
  }

  vec<vec<int>> city2;
  for (int i = 0; i < b; i++) {
    int d, e;
    cin >> d >> e;
    vec<int> temp;
    temp.pb(d);
    temp.pb(e);
    city2.push_back(temp);
  }

  UF uf(n);
  map<string, int> city_map;
  for (auto city : city1) {
    int c1 = city[0];
    int c2 = city[1];
    city_map[c1 < c2 ? c1 + "-" + c2 : c2 + "-" + c1] = city[2];
  }
  int res = 0;
  for (auto city : city2) {
    int c1 = city[0];
    int c2 = city[1];
    res += city_map[c1 < c2 ? c1 + "-" + c2 : c2 + "-" + c1];
    uf.union_connect(c1, c2);
  }

  if (uf.cnt == 1) {
    cout << res;
    return 0;
  }

  sort(city1.begin(), city1.end(), comp);

  for (auto city : city1) {
    int c1 = city[0];
    int c2 = city[1];
    if (uf.item[c1] != uf.item[c2]) {
      uf.union_connect(c1, c2);
      res += city_map[c1 < c2 ? c1 + "-" + c2 : c2 + "-" + c1];
    }
    if (uf.cnt == 1) {
      cout << res;
      return 0;
    }
  }

  if (uf.cnt > 1) {
    cout << "-1";
    return 0;
  }

  cout << res;

#ifdef TXT
  fclose(stdin);
  fclose(stdout);
#endif  // TXT
  return 0;
}