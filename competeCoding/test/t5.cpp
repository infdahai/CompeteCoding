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

bool cmp1(vec<int> &a, vec<int> &b) { return a[0] < b[0]; }

class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end(), cmp1);
    vec<vec<int>> res;

    for (int i = 0; i < intervals.size(); i++) {
      if (res.empty()) {
        res.push_back(intervals[i]);
        continue;
      }
      if (res.back()[1] >= intervals[i][0]) {
        int a = res.back()[0];
        int b = res.back()[1];
        res.pop_back();
        res.push_back(vector<int>{a, max(b, intervals[i][1])});
      } else {
        res.push_back(intervals[i]);
      }
    }

    return res;
  }
};

void printmerge(vec<vec<int>> &c) {
  for (auto &p : c) {
    cout << p[0] << " " << p[1] << "\n";
  }
}

int main() {
  {
    auto solu = Solution();
    vec<vec<int>> a = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};

    auto aa = solu.merge(a);
    printmerge(aa);

    vec<vec<int>> b = {{1, 4}, {4, 5}};
    auto bb = solu.merge(b);
    printmerge(bb);

    vec<vec<int>> c = {{1, 5}, {2, 6}, {4, 7}};
    auto cc = solu.merge(c);
    printmerge(cc);
  }

  return 0;
}