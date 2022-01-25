#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, q;
int cnt;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
string s;
void change(int pos, char ch) {
  rep(i, pos - 2, pos) if (i >= 1 && i + 2 <= n && s.substr(i, 3) == "abc")
      cnt--;
  s[pos] = ch;
  rep(i, pos - 2, pos) if (i >= 1 && i + 2 <= n && s.substr(i, 3) == "abc")
      cnt++;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> q >> s;
  s = '$' + s;
  rep(i, 1, n - 2) cnt += s.substr(i, 3) == "abc";
  rep(i, 1, q) {
    int pos;
    char ch;
    cin >> pos >> ch;
    change(pos, ch);
    cout << cnt << '\n';
  }

  return 0;
}