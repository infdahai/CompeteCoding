#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int n = 1e4 + 5;
string s[n], t[n], k;
ll a, b, res;
ll sec;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  while (getline(cin, k), k != "EOF") {
    a++;
    for (char i : k)
      if (i == '<') {
        if (!s[a].empty())
          s[a].pop_back();
      } else
        s[a].push_back(i);
  }
  while (getline(cin, k), k != "EOF") {
    if (++b > a)
      break;
    for (char i : k)
      if (i == '<') {
        if (!t[b].empty())
          t[b].pop_back();
      } else
        t[b].push_back(i);
    for (int j = 0; j < min(s[b].size(), t[b].size()); j++) {
      res += s[b][j] == t[b][j];
    }
  }
  cin >> sec;
  cout << ll(res * 60 / sec + 0.5);
  return 0;
}