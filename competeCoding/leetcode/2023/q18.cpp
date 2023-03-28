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

bool calc(int k, vec<int>& r, int sum) {
  if (sum % k != 0) {
    return false;
  }
  int p = sum / k;
  if (r.back() > p) {
    return false;
  }

  int m = r.size();

  vec<bool> dp(1 << m, false);
  vec<int> csum(1 << m, 0);
  dp[0] = true;
  for (int i = 0; i < 1 << m; i++) {
    if (!dp[i]) {
      continue;
    }
    for (int j = 0; j < m; j++) {
      if (csum[i] + r[j] > p) {
        break;
      }
      if (((i >> j) & 1) == 0) {
        int next = i | (1 << j);
        if (!dp[next]) {
          csum[next] = (csum[i] + r[j]) % p;
          dp[next] = true;
        }
      }
    }
  }

  return dp[(1 << m) - 1];
}

int main() {
  fast_io;

  int n;
  cin >> n;
  int sum = 0;
  vec<int> r;
  rep(i, 1, n, 1) {
    int a;
    cin >> a;
    sum += a;
    r.pb(a);
  }
  sort(r.begin(), r.end());
  for (int i = n; i >= 1; i--) {
    if (calc(i, r, sum)) {
      cout << i << endl;
      break;
    }
  }

  return 0;
}