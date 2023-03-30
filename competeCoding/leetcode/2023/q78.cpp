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

int main() {
  fast_io;

  string ts;
  getline(cin, ts);
  vec<int> par = split(ts);
  int a = par[0];
  int k = par[1];

  getline(cin, ts);
  vec<int> nums = split(ts);
  int res = 0;
  int l = 0;
  int r = 0;
  map<int, int> numcnt;

  while (l < a && r < a) {
    int c = nums[r];
    if (numcnt.count(c)) {
      numcnt[c]++;
    } else {
      numcnt[c] = 1;
    }

    if (numcnt[c] >= k) {
      res += a - r;
      numcnt[nums[l]]--;
      numcnt[c]--;
      l++;
      r--;
    }
    r++;
  }
  cout << res;

  return 0;
}