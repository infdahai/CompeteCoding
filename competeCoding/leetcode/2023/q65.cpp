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

int get_short(int a, int b) {
  if (a * 10 < b) {
    return a * 10;
  }
  return b;
}

int main() {
  fast_io;

  string inpstr;
  getline(cin, inpstr);
  int n = stoi(inpstr);
  getline(cin, inpstr);
  int t = stoi(inpstr);
  getline(cin, inpstr);
  vec<int> a = split(inpstr);

  sort(a.begin(), a.end());
  vec<int> dp(n, 0);
  dp[0] = a[0];
  if (dp[0] > t) {
    cout << "0 0";
    return 0;
  }
  dp[1] = get_short(a[0], a[1]);
  if (dp[1] > t) {
    cout << 1 << " " << dp[0];
    return 0;
  }

  for (int i = 2; i < n; i++) {
    dp[i] = min(dp[i - 1] + a[0] + get_short(a[0], a[i]),
                dp[i - 2] + a[0] + get_short(a[i - 1], a[i]) + a[1] + get_short(a[0], a[1]));

    if (dp[i] > t) {
      cout << i << " " << dp[i - 1];
      return 0;
    }
  }

  cout << n << " " << dp[n - 1];

  return 0;
}