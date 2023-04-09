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

struct lnode {
  int v;
  int next;
  lnode(int v, int next) : v(v), next(next) {}
};

// inputs.erase(remove(inputs.begin(), inputs.end(), '['), inputs.end());

bool comp1(vec<int> &a, vec<int> &b) { return a[0] < b[0]; }

struct comp2 {
  bool operator()(vec<int> &a, vec<int> &b) { return a[0] > b[0]; }
};

// #define TXT
int main() {
  fast_io;
#ifdef TXT
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif  // TXT

  int n;
  cin >> n;
  int t = 0;
  vec<vec<int>> res;
  for (int i = 0; i < n; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    vec<int> temp = {a, b, c};
    res.pb(temp);
  }

  sort(res.begin(), res.end(), comp1);
  priority_queue<vec<int>, vec<vec<int>>, comp2> pq;
  int ma = 0;
  for (int i = 0; i < res.size(); i++) {
    while (!pq.empty() && pq.top()[0] <= res[i][0]) {
      auto &top = pq.top();
      ma -= top[1];
      pq.pop();
    }

    ma += res[i][2];
    t = max(t, ma);
    vec<int> temp = {res[i][1], res[i][2]};
    pq.emplace(temp);
  }

  cout << t;

#ifdef TXT
  fclose(stdin);
  fclose(stdout);
#endif  // TXT
  return 0;
}