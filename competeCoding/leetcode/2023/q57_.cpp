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

void check(set<int>& temp, int ind, vec<vec<int>>& matrix) {
  for (int i = 0; i < matrix.size(); i++) {
    if (temp.count(i)) {
      continue;
    }
    if (i != ind && matrix[ind][i] == 1) {
      temp.insert(i);
      check(temp, i, matrix);
    }
  }
}

int main() {
  fast_io;

  int n;
  cin >> n;
  vec<vec<int>> matrix;
  rep(i, 1, n, 1) {
    vec<int> c;
    rep(j, 1, n, 1) {
      int b;
      cin >> b;
      c.pb(b);
    }
    matrix.pb(c);
  }

  int res = 0;
  set<int> ma;
  for (int i = 0; i < n; i++) {
    if (ma.count(i)) {
      continue;
    }
    set<int> temp;
    temp.insert(i);
    check(temp, i, matrix);
    ma.insert(temp.begin(), temp.end());
    res++;
  }

  cout << res;
  return 0;
}