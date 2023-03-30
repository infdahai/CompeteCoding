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
  while (is.find(",") != string::npos) {
    int found = is.find(",");
    v.push_back(stoi(is.substr(0, found)));
    is = is.substr(found + 1);
  }
  v.push_back(stoi(is));
  return v;
}

int main() {
  fast_io;

  string s;
  getline(cin, s);
  int n = stoi(s);

  string ts;
  getline(cin, ts);
  vec<int> nums = split(ts);

  deque<int> dq;
  for (int i = 0; i < nums.size(); i++) {
    // debug(nums[i]);
    if (i >= n) {
      cout << dq.front() << " ";
      if (nums[i - n] == dq.front()) {
        dq.pop_front();
      }
    }

    while (!dq.empty() && dq.back() > nums[i]) {
      dq.pop_back();
    }
    dq.push_back(nums[i]);
  }
  cout << dq.front() << endl;

  return 0;
}