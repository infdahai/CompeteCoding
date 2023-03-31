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

int get_area(vec<vec<int>> &ma, int c, int k) {
  int n = ma.size();
  int m = ma[0].size();
  vec<vec<int>> s(n + 1, vec<int>(m + 1, 0));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      s[i][j] = ma[i - 1][j - 1] + s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1];
    }
  }

  int ans = 0;
  for (int i = c; i <= n; i++) {
    for (int j = c; j <= m; j++) {
      int t = s[i][j] + s[i - c][j - c] - s[i - c][j] - s[i][j - c];
      if (t >= k) {
        ans++;
      }
    }
  }
  return ans;
}

#define TXT

int main() {
  fast_io;
#ifdef TXT
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif  // TXT

  string inputs;
  getline(cin, inputs);
  vec<int> params = split(inputs);
  int n = params[0];
  int m = params[1];
  int c = params[2];
  int k = params[3];

  vec<vec<int>> ma;
  for (int i = 0; i < n; i++) {
    getline(cin, inputs);
    ma.pb(split(inputs));
  }

  cout << get_area(ma, c, k) << endl;

#ifdef TXT
  fclose(stdin);
  fclose(stdout);
#endif  // TXT
  return 0;
}