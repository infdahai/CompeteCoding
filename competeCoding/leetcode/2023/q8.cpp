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

bool can(vec<int> &a, int k, int sum) {
  if (sum % k > 0) {
    return false;
  }
  int p = sum / k;
  if (a.back() > p) {
    return false;
  }
  int n = a.size();
  vec<bool> dp(1 << n, false);
  dp[0] = true;
  vec<int> cur(1 << n, 0);
  for (int i = 0; i < 1 << n; i++) {
    if (!dp[i]) {
      continue;
    }
    for (int j = 0; j < n; j++) {
      if (cur[i] + a[j] > p) {
        break;
      }
      if ((i & (1 << j)) == 0) {
        int next = i | (1 << j);
        if (!dp[next]) {
          dp[next] = true;
          cur[next] = (cur[i] + a[j]) % p;
        }
      }
    }
  }
  return dp[(1 << n) - 1];
}

struct lnode {
  int v;
  int next;
  lnode(int v, int next) : v(v), next(next) {}
};

// inputs.erase(remove(inputs.begin(), inputs.end(), '['), inputs.end());

// #define TXT
int main() {
  fast_io;
#ifdef TXT
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif  // TXT

  int m;
  cin >> m;
  vec<int> a;
  int sum = 0;
  rep(i, 1, m, 1) {
    int b;
    cin >> b;
    sum += b;
    a.pb(b);
  }

  sort(a.begin(), a.end());

  for (int i = m; i > 0; i--) {
    if (can(a, i, sum)) {
      cout << sum / i;
      return 0;
    }
  }

#ifdef TXT
  fclose(stdin);
  fclose(stdout);
#endif  // TXT
  return 0;
}