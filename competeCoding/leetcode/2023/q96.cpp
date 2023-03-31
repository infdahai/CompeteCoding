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

bool comp(vec<int> &x, vec<int> &y) {
  if (x[0] > y[0]) {
    return true;
  }
  if (x[0] == y[0]) {
    if (x[2] < y[2]) {
      return true;
    }
    if (x[2] == y[2]) {
      return x[1] < y[1];
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
  int n;
  cin >> n;
  vec<int> days;
  rep(i, 1, 30, 1) {
    int a;
    cin >> a;
    days.pb(a);
  }

  map<int, vec<int>> ma;
  for (int i = 0; i < 30; i++) {
    for (int j = 0; j < days[i]; j++) {
      int t;
      cin >> t;
      if (ma.count(t)) {
        auto &v = ma[t];
        v[0]++;
      } else {
        ma[t] = vec<int>{1, i};
      }
    }
  }

  vec<vec<int>> em;
  for (auto &it : ma) {
    vec<int> t;
    t.pb(it.first);
    t.pb(it.second[0]);
    t.pb(it.second[1]);
    em.pb(t);
  }
  sort(em.begin(), em.end(), comp);

  int sz = em.size() > 5 ? 5 : em.size();
  for (int i = 0; i < sz; i++) {
    cout << em[i][0] << " ";
  }

#ifdef TXT
  fclose(stdin);
  fclose(stdout);
#endif  // TXT
  return 0;
}