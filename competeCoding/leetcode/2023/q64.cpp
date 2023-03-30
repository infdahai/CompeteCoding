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

int solve(int n, vec<vec<int>> &mat) {
  int M = 1 << n;
  vec<vec<int>> res(1 << n, vec<int>(n, INF));
  res[1][0] = 0;

  for (int i = 1; i < M; i++) {
    for (int j = 0; j < n; j++) {
      if (((i >> j) & 1) == 0) {
        continue;
      }
      for (int k = 0; k < n; k++) {
        if ((i >> k) & 1) {
          debug(res[i ^ (1 << j)][k]);
          debug(res[i][j]);
          res[i][j] = min(res[i][j], mat[k][j] + res[i ^ (1 << j)][k]);
        }
      }
    }
  }
  int minval = 0x7f7f7f7f;
  for (int i = 0; i < n; i++) {
    minval = min(minval, res[M - 1][i] + mat[i][0]);
  }
  return minval;
}

int main() {
  fast_io;

  int n;
  cin >> n;
  vec<vec<int>> matrix(n, vec<int>(n, 0));
  rep(i, 1, n, 1) {
    rep(j, 1, n, 1) {
      int a;
      cin >> a;
      matrix[i - 1][j - 1] = a;
    }
  }
  cout << solve(n, matrix);

  return 0;
}