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
#define vec vector
using ll = long long;
#define INF 0x3f3f3f3f

inline int gcd(int a, int b) { return b > 0 ? gcd(b, a % b) : a; }

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

struct lnode {
  int v;
  int next;
  lnode(int v, int next) : v(v), next(next) {}
};

// inputs.erase(remove(inputs.begin(), inputs.end(), '['), inputs.end());

class Solution {
  using pii = pair<int, int>;

 public:
  int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
    int n = scores.size();
    vector<vector<pii>> g(n);
    for (auto& e : edges) {
      int x = e[0], y = e[1];
      g[x].emplace_back(-scores[y], y);
      g[y].emplace_back(-scores[x], x);
    }

    for (auto& vs : g) {
      if (vs.size() > 3) {
        nth_element(vs.begin(), vs.begin() + 3, vs.end());
        vs.resize(3);
      }
    }

    int ans = -1;
    for (auto& e : edges) {
      int x = e[0], y = e[1];
      for (auto& [score_a, a] : g[x]) {
        for (auto& [score_b, b] : g[y]) {
          if (a != y && b != x && a != b) {
            ans = max(ans, -score_a + scores[x] + scores[y] - score_b);
          }
        }
      }
    }
    return ans;
  }
};

// #define TXT
int main() {
  fast_io;
#ifdef TXT
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif  // TXT

#ifdef TXT
  fclose(stdin);
  fclose(stdout);
#endif  // TXT
  return 0;
}