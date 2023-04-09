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

// inputs.erase(remove(inputs.begin(), inputs.end(), '['), inputs.end());

// #define TXT
int main() {
  fast_io;
#ifdef TXT
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif  // TXT

  int m, n, x;
  cin >> m >> n >> x;
  if (n >= m) {
    cout << 0;
    return 0;
  }

  if (n <= x) {
    if (n < floor(x / 2)) {
      m -= x - n;
    }
    cout << (int)ceil((double)m / x) + 1;
    return 0;
  }

  int res = 2;
  n -= x - 1;
  m -= x;
  int c1 = x;
  int c2 = x - 1;

  int t1 = (int)ceil(x / 2) + (x % 2 == 0 ? 1 : 0);
  int t2 = x - t1;

  while (m > 0) {
    if (m - t1 > n - t2 || (m == t1 || n == t2)) {
      m -= t1;
      c1 += t1;
      n -= t2;
      c2 += t2;
      res++;
    } else {
      int tmp = c1 - c2 - 1;
      if (tmp == 0) {
        cout << 0;
        return 0;
      }
      n -= tmp;
      c2 += tmp;
      res++;
    }
  }

  cout << res;
#ifdef TXT
  fclose(stdin);
  fclose(stdout);
#endif  // TXT
  return 0;
}