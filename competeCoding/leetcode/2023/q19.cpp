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

vec<int> split(string is) {
  vec<int> v;
  while (is.find(",") != string::npos) {
    int found = is.find(",");
    v.push_back(stoi(is.substr(0, found)));
    is = is.substr(found + 1);
  }
  v.push_back(stoi(is));
  return v;
}

bool cmp(pair<int, int>& a, pair<int, int>& b) {
  if (a.first < b.first) {
    return true;
  }
  return a.first == b.first && a.second < b.second;
}

int main() {
  fast_io;

  string rs;
  cin >> rs;
  rs.erase(remove(rs.begin(), rs.end(), '['), rs.end());
  rs.erase(remove(rs.begin(), rs.end(), ']'), rs.end());

  vec<pair<int, int>> ranges;
  {
    vec<int> ts = split(rs);
    for (int i = 0; i < ts.size(); i += 2) {
      ranges.pb(mp(ts[i], ts[i + 1]));
    }
  }

  string conn;
  cin >> conn;

  {
    int a = conn.find("[");
    int b = conn.find("]");
    conn = conn.substr(a + 1, b);
  }
  vector<int> cons = split(conn);

  sort(cons.begin(), cons.end());
  sort(ranges.begin(), ranges.end(), cmp);

  vec<pair<int, int>> mr;
  mr.pb(ranges[0]);

  vec<int> rdiff;
  for (int i = 1; i < ranges.size(); i++) {
    auto& r1 = mr[mr.size() - 1];
    auto& r2 = ranges[i];

    if (r2.first <= r1.second) {
      mr.pop_back();
      mr.pb(mp(r1.first, max(r1.second, r2.second)));
    } else {
      rdiff.pb(r2.first - r1.second);
      mr.pb(r2);
    }
  }

  sort(rdiff.begin(), rdiff.end());
  int res = mr.size();
  int idx = 0;
  for (int i = 0; i < cons.size() && idx < rdiff.size(); i++) {
    if (cons[i] >= rdiff[idx]) {
      idx++;
      res--;
    }
  }
  cout << res;

  return 0;
}