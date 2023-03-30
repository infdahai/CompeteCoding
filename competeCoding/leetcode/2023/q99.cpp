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

int comp(string& s) {
  if (s.size() <= 1) {
    return 0;
  }
  int dp0 = 0, dp1 = 0;
  for (auto c : s) {
    int d0 = dp0, d1 = min(dp0, dp1);
    if (c == 'A') {
      d1++;
    } else {
      d0++;
    }
    dp0 = d0;
    dp1 = d1;
  }
  return min(dp0, dp1);
}

int main() {
  fast_io;

  string s;
  cin >> s;

  cout << comp(s);
  return 0;
}