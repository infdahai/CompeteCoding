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
  vector<int> minReverseOperations(int n, int p, vector<int>& banned, int k) {
    vector<int> ans(n, -1);
    if (k == 1) {
      ans[p] = 0;
      return ans;
    }

    unordered_set<int> ban;
    for (int x : banned) ban.insert(x);

    set<int> st[2];
    for (int i = 0; i < n; i++) {
      if (i != p && ban.count(i) == 0) {
        st[i % 2].insert(i);
      }
    }

    queue<int> q;
    q.push(p);
    ans[p] = 0;
    while (!q.empty()) {
      int now = q.front();
      q.pop();

      int L, R;
      L = max(-(k - 1), k - 1 - now * 2);
      R = min(k - 1, -(k - 1) + 2 * (n - now - 1));

      int x = (now + (k - 1)) % 2;
      auto it = st[x].lower_bound(now + L);
      while (it != st[x].end()) {
        if (*it > now + R) break;
        ans[*it] = ans[now] + 1;
        q.push(*it);
        it = st[x].erase(it);
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