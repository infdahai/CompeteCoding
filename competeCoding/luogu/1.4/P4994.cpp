#include <bits/stdc++.h>

using ll = long long;
using namespace std;
const int n = 1e7;
int m;
bool isNotPrime[n];
int f[n], zhi[n], e;
inline void sai(int maxe) {
  for (int i = 2; i <= maxe; i++)
    if (!isNotPrime[i]) {
      zhi[++e] = i;
      for (int j = i; j <= maxe / i; j++)
        isNotPrime[i * j] = 1;
    }
}
inline int gcd(int x, int y) { return x % y == 0 ? y : gcd(y, x % y); }
inline int lcm(int x, int y) { return x / gcd(x, y) * y; }

inline int bf(int x) {
  f[1] = 1;
  for (int i = 1; i; ++i) {
    f[i] = f[i - 1] + f[i - 2];
    f[i] %= x;
    if (f[i] == 1 && f[i - 1] == 0)
      return i - 1;
  }
}

inline int ksm(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1)
      ans *= a;
    a *= a;
    b >>= 1;
  }
  return ans;
}

inline int div(int a) {
  int ans = 1;
  for (int i = 1; i <= e; i++) {
    if (zhi[i] > a)
      break;
    if (a % zhi[i] == 0) {
      int tim = 0;
      while (a % zhi[i] == 0)
        tim++, a /= zhi[i];
      int ti = bf(zhi[i]);
      ti *= ksm(zhi[i], tim - 1);
      ans = lcm(ans, ti);
    }
  }
  return ans;
}

int main() {
  sai(706150);
  int x;
  cin >> x;
  cout << div(x);
  return 0;
}