#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int n, k;
ll a[25];
bool isp(int n) {
  int k = sqrt(double(n));
  for (int i = 2; i <= k; i++)
    if (n % i == 0)
      return false;
  return true;
}

int res(int k1, int add, int begin, int end) {
  if (k1 == 0)
    return isp(add);
  int sum = 0;
  for (int i = begin; i < end; i++)
    sum += res(k1 - 1, add + a[i], i + 1, end);
  return sum;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> k;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  cout << res(k, 0, 0, n);
  return 0;
}