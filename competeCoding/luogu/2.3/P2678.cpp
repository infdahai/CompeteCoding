#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int d, n, m;
const int maxn = 500010;
int a[maxn];
int l, r, mid, ans;
inline int read() {
  int num = 0;
  char c;
  bool flag = false;
  while ((c = getchar()) == ' ' || c == '\n' || c == '\r')
    ;
  if (c == '-')
    flag = true;
  else
    num = c - '0';
  while (isdigit(c = getchar()))
    num = num * 10 + c - '0';
  return (flag ? -1 : 1) * num;
}
bool judge(int x) {
  int tot = 0;
  int i = 0;
  int now = 0;
  while (i < n + 1) {
    i++;
    if (a[i] - a[now] < x)
      tot++;
    else
      now = i;
  }
  if (tot > m)
    return false;
  else
    return true;
}
int main() {
  d = read();
  n = read();
  m = read();
  for (int i = 1; i <= n; i++)
    a[i] = read();
  a[n + 1] = d;
  l = 1;
  r = d;
  while (l <= r) {
    mid = l + (r - l) / 2;
    if (judge(mid)) {
      ans = mid;
      l = mid + 1;
    } else
      r = mid - 1;
  }
  cout << ans;
  return 0;
}