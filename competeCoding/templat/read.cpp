#include <bits/stdc++.h>
#define debug(x) cout << "[debug]" #x << "=" << x << endl;
#define fast_io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (b); i >= (a); i--)
#define mp make_pair
#define pb push_back
using ll = long long;
int read() {
  int x = 0, w = 1;
  char ch = 0;
  while (ch < '0' || ch > '9') {
    if (ch == '-')
      w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * w;
}

void write(int x) {
  if (x < 0) {
    x = -x;
    putchar('-');
  }
  if (x > 9)
    write(x / 10);
  putchar(x % 10 + '0');
}

inline void write1(int x) {
  static int sta[35];
  int top = 0;
  do {
    sta[top++] = x % 10, x /= 10;
  } while (x);
  while (top)
    putchar(sta[--top] + '0');
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  return 0;
}