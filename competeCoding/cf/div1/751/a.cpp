#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << "[debug]" #x << "=" << x << endl;
#define fast_io                                                                \
  ios::sync_with_stdio(0);                                                     \
  cin.tie(0);                                                                  \
  cout.tie(0)
#define rep(i, a, b, c) for (int i = (a); i <= (b); i += (c))
#define per(i, a, b, c) for (int i = (a); i >= (b); i -= (c))
#define endl "\n"
#define mp make_pair
#define pb push_back
using ll = long long;
string s, b;
char a;
int main() {
  fast_io;
  int tt;
  cin >> tt;
  while (tt--) {
    cin >> s;
    int k = 'z', ind = 0;
    rep(i, 0, s.size() - 1, 1) {
      if (s[i] < k) {
        k = s[i], ind = i;
      }
    }
    a = k;
    b = s.erase(ind, 1);
    cout << a << " " << b << endl;
  }
  return 0;
}