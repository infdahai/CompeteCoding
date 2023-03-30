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

int comp(string s, bool flag) {
  int l = 0, r = s.size() - 1;
  int cnt = 0;
  while (r >= l) {
    while (s[l] == 'A') {
      l++;
    }
    while (s[r] == 'B') {
      r--;
    }
    if (r < l) {
      break;
    }
    if (flag) {
      s[l] = 'A';
    } else {
      s[r] = 'B';
    }
    cnt++;
  }
  return cnt;
}

int main() {
  fast_io;

  string s;
  cin >> s;

  if (s.size() <= 1) {
    cout << s;
    return 0;
  }

  // int ca = 0, cb = 0;
  // for (int i = 0; i < s.size(); i++) {
  //   if (s[i] == 'A') {
  //     ca++;
  //   } else {
  //     cb++;
  //   }
  // }

  cout << min(comp(s, true), comp(s, false));
  return 0;
}