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

bool check(string& s1, string& s2) {
  unordered_set<char> a1, a2;

  for (auto& x : s1) {
    a1.insert(x);
  }
  for (auto& x : s2) {
    a2.insert(x);
  }

  for (auto& x : a1) {
    if (a2.count(x) == 0) {
      return false;
    }
  }
  return true;
}

void dfs(int n, vec<string>& res, string& ns, map<int, string>& m, string& ts) {
  if (n == ns.size()) {
    res.push_back(ts);
    return;
  }
  for (auto& x : m[ns[n]]) {
    ts += x;
    dfs(n + 1, res, ns, m, ts);
    ts = ts.substr(0, n);
  }
}

int main() {
  fast_io;

  map<int, string> m;
  m['0'] = "abc";
  m['1'] = "def";
  m['2'] = "ghi";
  m['3'] = "jkl";
  m['4'] = "mno";
  m['5'] = "pqr";
  m['6'] = "st";
  m['7'] = "uv";
  m['8'] = "wx";
  m['9'] = "yz";

  string ns, bs;
  cin >> ns >> bs;
  vec<string> res;
  string ts{};

  dfs(0, res, ns, m, ts);
  string os{};
  for (auto& x : res) {
    if (!check(bs, x)) {
      os += x + ' ';
    }
  }
  os.erase(os.find_last_not_of(" ") + 1);
  cout << os;

  return 0;
}