#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << "[debug]" #x << "=" << x << endl;
#define fast_io            \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0)
#define rep(i, a, b, c) for (int i = (a); i <= (b); i += (c))
#define per(i, a, b, c) for (int i = (a); i >= (b); i -= (c))
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

class Solution1 {
  using ll = long long;

 public:
  vector<ll> distance(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) mp[nums[i]].push_back(i);

    vector<long long> ans(n);
    long long s[n + 1];
    s[0] = 0;
    for (auto& [_, v] : mp) {
      int m = v.size();
      for (int i = 0; i < m; i++) s[i + 1] = s[i] + v[i];
      for (int i = 0; i < m; i++) {
        long long target = v[i];
        long long l = target * i - s[i];
        long long r = s[m] - s[i] - target * (m - i);
        ans[target] = l + r;
      }
    }
    return ans;
  }
};

class Solution {
  using ll = long long;

 public:
  vector<ll> distance(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) mp[nums[i]].push_back(i);

    vector<long long> ans(n);
    for (auto& [_, v] : mp) {
      int m = v.size();
      long long s = accumulate(v.begin(), v.end(), 0) - m * v[0];
      ans[v[0]] = s;
      for (int i = 1; i < m; i++) {
        int d = v[i] - v[i - 1];
        ans[v[i]] = ans[v[i - 1]] - (n - 2 * i) * d;
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