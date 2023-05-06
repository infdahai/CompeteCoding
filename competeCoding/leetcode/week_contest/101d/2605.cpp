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

class Solution1 {
 public:
  int minNumber(vector<int>& nums1, vector<int>& nums2) {
    set<int> s1(nums1.begin(), nums1.end());
    set<int> s2(nums2.begin(), nums2.end());
    for (int x : s1) {
      if (s2.count(x)) {
        return x;
      }
    }
    int ans1 = *(s1.begin()) * 10 + *s2.begin();
    int ans2 = *s2.begin() * 10 + *s1.begin();
    return min(ans1, ans2);
  }
};

class Solution {
 public:
  int minNumber(vector<int>& nums1, vector<int>& nums2) {
    int m1 = 0, m2 = 0;
    for (int x : nums1) m1 |= 1 << x;
    for (int x : nums2) m2 |= 1 << x;
    int m = m1 & m2;
    if (m) return __builtin_ctz(m);
    int x = __builtin_ctz(m1), y = __builtin_ctz(m2);
    return min(x * 10 + y, y * 10 + x);
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