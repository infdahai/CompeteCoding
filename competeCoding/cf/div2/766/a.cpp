#include <bits/stdc++.h>
using namespace std;
#define ONLINE_JUDGE
int t, n, m, r, c;
int mp[51][51];
int bflag;
char s;
int num;
#define _rep(i, a, b) for (int i = (a); i <= (b); i++)

void solve() {
  cin >> n >> m >> r >> c;
  bflag = 0;
  num = 0;
  _rep(i, 1, n) {
    _rep(j, 1, m) {
      cin >> s;
      if (s == 'B') {
        bflag++;
        mp[i][j] = 1;
      } else
        mp[i][j] = 0;
    }
  }
  // _rep(i,1,n){
  //   _rep(j,1,m){
  //     cout<<mp[i][j];
  //   }
  //   cout<<"\n";
  // }
  // cout<<"\n\n";
  if (bflag == 0) {
    cout << -1 << "\n";
    return;
  }
  if (mp[r][c] == 1) {
    cout << 0 << "\n";
    return;
  }
  _rep(j, 1, m) {
    if (mp[r][j] == 1) {
      num = 1;
      break;
    }
  }
  _rep(i, 1, n) {
    if (mp[i][c] == 1) {
      num = 1;
      break;
    }
  }
  if (num == 1) {
    cout << 1 << "\n";
    return;
  }
  cout << 2 << "\n";
  return;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}