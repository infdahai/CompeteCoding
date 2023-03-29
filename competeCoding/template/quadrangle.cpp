//
// Divide and Conquer DP
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
namespace DivConq {
int m, n;
vector<ll> dp_before(n), dp_cur(n);
ll C(int i, int j);

void compute(int l, int r, int optl, int optr) {
  if (l > r)
    return;
  int mid = (l + r) >> 1;
  pair<ll, int> best = {LLONG_MAX, -1};
  for (int k = optl; k <= min(mid, optr); k++) {
    best = min(best, {(k ? dp_before[k - 1] : 0) + C(k, mid), k});
  }

  dp_cur[mid] = best.first;
  int opt = best.second;
  compute(l, mid - 1, optl, opt);
  compute(mid + 1, r, opt, optr);
}

int solve() {
  for (int i = 0; i < n; i++)
    dp_before[i] = C(0, i);
  for (int i = 1; i < m; i++) {
    compute(0, n - 1, 0, n - 1);
    dp_before = dp_cur;
  }
  return (int)dp_before[n - 1];
}
} // namespace DivConq

// xDyD DP
namespace XDYDDP {
struct Node {
  ll p, l, r;
};

int f(int i, int j);
int m, n;
vector<int> dp(n);
deque<Node> dq;
void solve() {
  for (int i = 1; i <= n; i++) {
    dp[i] = f(dq.front().p, i);
    if (dq.front().r == i)
      dq.pop_front();
    else
      dq.front().l++;

    while (!dq.empty() && f(i, dq.back().l) < f(dq.back().p, dq.back().l))
      dq.pop_back();
    if (dq.empty())
      dq.push_back({i, i + 1, n});
    else {
      int l = dq.back().l, r = dq.back().r;
      while (l < r) {
        int mid = r - (r - l) / 2;
        if (f(l, mid) < f(dq.back().p, mid))
          r = mid - 1;
        else
          l = mid;
      }
      dq.back().r = l;
      if(l!=n)
        dq.push_back({i,l+1,n});
    }
  }
}
} // namespace XDYDDP
