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

vec<int> comp(vec<int>& nums) {
  if (nums.empty()) {
    return nums;
  }
  int sz = nums.size();
  vec<int> res(sz, -1);
  stack<int> s;
  s.push(0);
  int ind = 1;
  while (ind < sz) {
    if (!s.empty() && nums[ind] > nums[s.top()]) {
      res[s.top()] = (ind - s.top()) * (nums[ind] - nums[s.top()]);
      s.pop();
    } else {
      s.push(ind);
      ind++;
    }
  }

  return res;
}

int main() {
  fast_io;

  string s;
  getline(cin, s);
  int n = stoi(s);

  string ts;
  getline(cin, ts);
  vector<int> nums = split(ts);

  vec<int> res = comp(nums);

  for (int i = 0; i < res.size(); i++) {
    if (res[i] == -1) {
      cout << nums[i] << " ";
    } else {
      cout << res[i] << " ";
    }
  }

  return 0;
}