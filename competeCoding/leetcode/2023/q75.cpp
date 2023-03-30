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

  string inpustr;
  getline(cin, inpustr);
  vec<int> height = split(inpustr);
  int l = 0, r = height.size() - 1;

  vec<int> res(3, 0);
  int cap = 0;

  while (l < r) {
    int sum = 0;
    int low = min(height[l], height[r]);

    for (int i = l; i <= r; i++) {
      sum += max(0, low - height[i]);
    }

    if (sum >= cap) {
      res = vec<int>{l, r, sum};
      cap = sum;
    }

    if (height[r - 1] >= height[l] && height[r - 1] >= height[r]) {
      r--;
    } else if (height[l] < height[r]) {
      l++;
    } else if (height[l + 1] >= height[l] && height[l + 1] >= height[r]) {
      l++;
    } else if (height[l] > height[r]) {
      r--;
    } else {
      r--;
    }
  }

  if (res[2] == 0) {
    cout << 0;
  } else {
    cout << res[0] << " " << res[1] << ":" << res[2];
  }
  return 0;
}