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

int dfs(vec<int> &lines, int ind) {
  int v = 0;
  int sz = lines.size();
  int a, b, c;
  for (int i = ind; i < sz - 2; i++) {
    a = lines[i];
    if (lines[a] == 0) {
      continue;
    }
    for (int j = i + 1; j < sz - 1; j++) {
      b = lines[j];
      if (lines[b] == 0) {
        continue;
      }
      for (int k = j + 1; k < sz; k++) {
        c = lines[k];
        if (lines[c] == 0) {
          continue;
        }
        if ((a * a + b * b) == c * c) {
          lines[a] = 0;
          lines[b] = 0;
          lines[c] = 0;
          v = max(v, dfs(lines, i + 1) + 1);
          lines[a] = a;
          lines[b] = b;
          lines[c] = c;
        }
      }
    }
  }
  return v;
}

// #define TXT
int main() {
  fast_io;
#ifdef TXT
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif  // TXT

  int t;
  cin >> t;
  vec<int> nums;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    for (int j = 0; j < n; j++) {
      int a;
      cin >> a;
      nums.pb(a);
    }
  }

  sort(nums.begin(), nums.end());
  cout << dfs(nums, 0);

#ifdef TXT
  fclose(stdin);
  fclose(stdout);
#endif  // TXT
  return 0;
}