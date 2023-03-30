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

void get_nums(vec<int> &nums) {
  vec<int> res;
  unordered_map<int, int> cnt, st_cnt;
  for (auto v : nums) {
    cnt[v]++;
  }

  res.emplace_back(-1);
  for (auto x : nums) {
    if (st_cnt[x] == 2) {
      continue;
    }

    while (x > res.back() && cnt[res.back()] > 2) {
      cnt[res.back()]--;
      st_cnt[res.back()]--;
      res.pop_back();
    }
    res.emplace_back(x);
    st_cnt[x]++;
  }

  for (int i = 1; i < res.size(); i++) {
    cout << res[i];
  }
}

int main() {
  fast_io;

  string inputs;
  cin >> inputs;
  vec<int> nums;
  for (auto c : inputs) {
    nums.pb(c - '0');
  }

  get_nums(nums);

  return 0;
}