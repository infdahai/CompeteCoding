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

int min_num;
int m;
int dfs(vec<int> &nums, int ind, int sum, int cnt) {
  if (sum > m) {
    return cnt;
  }
  if (sum <= m && sum > m - min_num) {
    return cnt + 1;
  }
  for (int i = ind; i < nums.size(); i++) {
    cnt = dfs(nums, i, sum + nums[i], cnt);
  }

  return cnt;
}

int main() {
  fast_io;
  string inputs;
  getline(cin, inputs);
  vec<int> nums = split(inputs);
  getline(cin, inputs);
  m = stoi(inputs);

  sort(nums.begin(), nums.end());
  min_num = nums[0];

  cout << dfs(nums, 0, 0, 0);

  return 0;
}