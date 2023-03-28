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

vec<string> split(string is) {
  vec<string> v;
  while (is.find(" ") != string::npos) {
    int found = is.find(" ");
    v.push_back(is.substr(0, found));
    is = is.substr(found + 1);
  }
  v.push_back(is);
  return v;
}

int main() {
  fast_io;

  int n;
  cin >> n;

  vec<vec<string>> v;
  rep(i, 1, 2 * n, 1) {
    string s;
    getline(cin, s);
    v.push_back(split(s));
  }

  bool ord = true;
  int res = 0;
  int sz = 0;
  for (int i = 0; i < v.size(); i++) {
    vec<string> os = v[i];
    if (os[0] == "head") {
      if (sz > 0 && ord) {
        ord = false;
      }
      sz++;
    } else if (os[0] == "tail") {
      sz++;
    } else {
      if (sz == 0) {
        continue;
      }
      if (!ord) {
        ord = true;
        res++;
      }
      sz--;
    }
  }

  cout << res;
  return 0;
}