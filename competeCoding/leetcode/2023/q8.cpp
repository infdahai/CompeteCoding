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
int m;

bool comp(const vec<int>& a, int k, int sum) {
  if (sum % k != 0) {
    return false;
  }

  int per = sum / k;

  vec<bool> d((1 << m), false);
  d[0] = true;
  vec<int> cnt(1 << m, 0);
  for (int i = 0; i < (1 << m) - 1; i++) {
    if (!d[i]) {
      continue;
    }
    for (int j = 0; j < m; j++) {
      if (cnt[i] + a[j] > per) {
        break;
      }
      if (((i >> j) & 1) == 0) {
        int next = i | (1 << j);
        if (!d[next]) {
          cnt[next] = (cnt[i] + a[j]) % per;
          d[next] = true;
        }
      }
    }
  }

  return d[(1 << m) - 1];
}

int main() {
  fast_io;

  cin >> m;
  vec<int> a;
  int sum = 0;
  rep(i, 1, m, 1) {
    int b;
    cin >> b;
    sum += b;
    a.push_back(b);
  }
  sort(a.begin(), a.end());

  for (int i = m; i > 0; i--) {
    if (comp(a, i, sum)) {
      cout << sum / i;
      break;
    }
  }

  return 0;
}