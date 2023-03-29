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

vec<string> split(string is) {
  vec<string> v;
  while (is.find(" ") != string::npos) {
    int found = is.find(" ");
    v.push_back(is.substr(0, found));
    is = is.substr(found + 1);
  }
  v.push_back(is);
  return v;
}

int main() {
  fast_io;

  int n;
  cin >> n;

  vec<int> nums;
  rep(i, 1, n, 1) {
    int a;
    cin >> a;
    nums.pb(a);
  }

  vec<int> bits(100, 0);
  for (auto& num : nums) {
    bitset<32> num_bin(num);
    string num_bin_str = num_bin.to_string();
    num_bin_str.erase(0, num_bin_str.find_first_not_of("0"));
    // int len = num_bin_str.size();

    if ("" == num_bin_str) {
      bits[0]++;
    } else {
      bits[num_bin_str.size()]++;
    }
  }

  int res = 0;
  for (int i = 0; i < bits.size(); i++) {
    for (int j = i + 1; j < bits.size(); j++) {
      res += bits[i] * bits[j];
    }
  }
  cout << res;
  return 0;
}