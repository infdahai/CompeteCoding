#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << "[debug]" #x << "=" << x << endl;
#define fast_io            \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0)
#define rep(i, a, b, c) for (int i = (a); i <= (b); i += (c))
#define per(i, a, b, c) for (int i = (a); i >= (b); i -= (c))
#define endl "\n"
#define mp make_pair
#define pb push_back
#define vec std::vector
using ll = long long;

pair<int, int> split(string s) {
  int found = s.find(",");
  int a = stoi(s.substr(0, found));
  int b = stoi(s.substr(found + 1));
  return mp(a, b);
}

bool comp(pair<int, int>& a, pair<int, int>& b) { return a.first < b.first; }

int main() {
  fast_io;

  int n;
  cin >> n;
  vector<pair<int, int>> ranges;
  rep(i, 1, n, 1) {
    string s;
    cin >> s;
    ranges.push_back(split(s));
  }

  sort(ranges.begin(), ranges.end(), comp);

  vec<pair<int, int>> res;
  res.push_back(ranges[0]);
  for (int i = 1; i < n; i++) {
    pair<int, int> range = ranges[i];
    while (true) {
      if (res.size() == 0) {
        res.push_back(range);
        break;
      }
      auto [s1, e1] = res[res.size() - 1];
      auto [s2, e2] = range;
      // debug(s1);
      // debug(e1);
      // debug(s2);
      // debug(e2);
      // debug(res.size());
      if (s2 <= s1) {
        // s2 == s1
        if (e2 > e1) {
          res.pop_back();
        } else {
          break;
        }

      } else {
        if (s2 < e1) {
          if (e2 <= e1) {
            break;
          } else {
            res.push_back(mp(e1, e2));
            break;
          }
        } else {
          // s2>=e1 => s2==e1
          res.push_back(range);
          break;
        }
      }
    }
  }

  cout << res.size();

  return 0;
}