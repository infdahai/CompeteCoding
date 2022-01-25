#include <bits/stdc++.h>
using namespace std;
int win[62503];
int a, b;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  char s;
  for (int i = 1; cin >> s && s != 'E'; i++) {
    win[i] = (s == 'W') ? 1 : 2;
  }
  for (int i = 1; 1; i++) {
    if (win[i] == 1)
      a++;
    if (win[i] == 2)
      b++;
    if (win[i] == 0) {
      cout << a << ":" << b << "\n\n";
      break;
    }
    if (abs(a - b) >= 2)
      if (a >= 11 || b >= 11) {
        cout << a << ":" << b << "\n";
        a = b = 0;
      }
  }
  a = b = 0;
  for (int i = 1; 1; i++) {
    if (win[i] == 1)
      a++;
    if (win[i] == 2)
      b++;
    if (win[i] == 0) {
      cout << a << ":" << b;
      break;
    }
    if (abs(a - b) >= 2)
      if (a >= 21 || b >= 21) {
        cout << a << ":" << b << "\n";
        a = b = 0;
      }
  }

  return 0;
}
