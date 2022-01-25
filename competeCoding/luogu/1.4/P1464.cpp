#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll a, b, c;
ll n;
ll w_mem[21][21][21];

#define wmem(x, y, z)                                                          \
  ((w_mem[x][y][z]) ? w_mem[x][y][z] : w_mem[x][y][z] = res(x, y, z))

ll res(ll x, ll y, ll z) {

  if (x <= 0 || y <= 0 || z <= 0)
    return 1;
  if (x > 20 || y > 20 || z > 20)
    return wmem(20, 20, 20);
  if (x < y && y < z)
    return wmem(x, y, z - 1) + wmem(x, y - 1, z - 1) - wmem(x, y - 1, z);

  return wmem(x - 1, y, z) + wmem(x - 1, y - 1, z) + wmem(x - 1, y, z - 1) -
         wmem(x - 1, y - 1, z - 1);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  while (cin >> a >> b >> c) {
    if (a == -1 && b == -1 && c == -1)
      break;
    ll d = res(a, b, c);
    cout << "w(" << a << ", " << b << ", " << c << ") = ";
    cout << d << "\n";
  }

  return 0; // nothing
}