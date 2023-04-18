#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#include <queue>
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define as_int(a) static_cast<int>(a)

//#ifdef ONLINE_JUDGE
int main() {
  int n, k;
  cin >> n >> k;
  vector<ll> av(n);
  rep(i, n) cin >> av[i];
  set<ll> st;
  rep(i, n) st.insert(av[i]);

  ll price;
  rep(i, k) {
    // cout << "hi " << endl;
    price = *st.begin();
    // cout << price << endl;
    st.erase(price);
    rep(i, n) st.insert(price + av[i]);
    // cout << "doge" << endl;
    while (as_int(st.size()) > k) {
      //      cout << " from " << endl;

      ll drop = *prev(st.end());
      // cout << "drop: " << drop << endl;
      st.erase(drop);
    }
  }
  cout << price << endl;
  return 0;
}
//#endif
