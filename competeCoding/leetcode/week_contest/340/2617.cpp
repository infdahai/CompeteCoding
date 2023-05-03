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
 public:
  int minimumVisitedCells(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    int mn = 0;
    vector<vector<pair<int, int>>> col_st(n);
    for (int i = m - 1; i >= 0; i--) {
      vector<pair<int, int>> st;
      for (int j = n - 1; j >= 0; j--) {
        auto& st2 = col_st[j];
        mn = INT_MAX;
        if (i == m - 1 && j == n - 1) {
          mn = 0;
        } else if (int g = grid[i][j]; g) {
          auto it = lower_bound(
              st.begin(), st.end(), j + g,
              [](const auto& a, const int b) { return a.second > b; });
          if (it < st.end()) mn = min(mn, it->first);
          it = lower_bound(
              st2.begin(), st2.end(), i + g,
              [](const auto& a, const int b) { return a.second > b; });
          if (it < st2.end()) mn = min(mn, it->first);
        }
        if (mn == INT_MAX) continue;

        ++mn;
        while (!st.empty() && mn <= st.back().first) st.pop_back();
        st.emplace_back(mn, j);
        while (!st2.empty() && mn <= st2.back().first) st2.pop_back();
        st2.emplace_back(mn, i);
      }
    }
    return mn < INT_MAX ? mn : -1;
  }
};

class Solution1 {
    
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