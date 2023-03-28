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
int m;
int comp(vec<vec<int>>& ma, int t, int c) {
  // assert(ma[0].size == m);
  int n = ma.size();
  m = ma[0].size();

  vec<vec<int>> s(n + 1, vec<int>(m + 1));
  rep(i, 1, n, 1) {
    rep(j, 1, m, 1) {
      s[i][j] = ma[i - 1][j - 1] - s[i - 1][j - 1] + s[i - 1][j] + s[i][j - 1];
    }
  }
  int ans = 0;
  rep(i, c, n, 1) {
    rep(j, c, m, 1) {
      int v = s[i][j] + s[i - c][j - c] - s[i - c][j] - s[i][j - c];
      if (v >= t) {
        ans++;
      }
    }
  }
  return ans;
}

int main() {
  fast_io;

  string is;
  getline(cin, is);
  vec<int> iv = split(is);
  int n, c, k;
  n = iv[0];
  m = iv[1];
  c = iv[2];
  k = iv[3];

  vec<vec<int>> ma;
  for (int i = 0; i < n; i++) {
    string s;
    getline(cin, s);
    ma.push_back(split(s));
  }

  cout << comp(ma, k, c) << endl;

  return 0;
}