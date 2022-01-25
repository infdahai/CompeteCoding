#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll d;
ll a, b, n;
int main() {
  cin >> a >> b >> n;
  d = b - a;
  cout << (n * a) + d * (n - 1) * n / 2;
  return 0; // nothing
}