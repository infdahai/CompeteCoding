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

  string cs;
  getline(cin, cs);
  int n = stoi(cs);

  string ms;
  getline(cin, ms);
  vec<int> nodes = split(ms);
  sort(nodes.begin(), nodes.end());

  if (n % 2 == 0) {
    cout << nodes[n / 2 - 1];
  } else {
    cout << nodes[n / 2];
  }

  return 0;
}