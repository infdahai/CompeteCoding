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

// #define TXT
int main() {
  fast_io;
#ifdef TXT
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif  // TXT

  int k;
  cin >> k;
  vec<vec<int>> data(101, vec<int>(101, 0));
  rep(i, 1, k, 1) {
    int a, b;
    cin >> a >> b;
    data[a][b] += 1;
  }
  int c;
  cin >> c;

  int l = 0, m1 = 0, m2 = 0, n = 0;
  rep(i, 1, 100, 1) {
    m1 += data[c][i];
    m2 += data[i][c];
    if (data[c][i] > 0 && data[i][c] == 0) {
      l++;
    }
    if (data[c][i] - data[i][c] > 5) {
      n++;
    }
  }
  int m = m1 - m2;
  bool flag = (l > 5) || (m > 10) || (n > 5);
  cout << (flag ? "true" : "false") << " " << l << " " << m;

#ifdef TXT
  fclose(stdin);
  fclose(stdout);
#endif  // TXT
  return 0;
}