#include <bits/stdc++.h>

using namespace std;

char str[] = {
    'K', 'Q', 'R', 'B', 'N',
};
int b1 = -1, b2 = -1;
int r1 = -1, r2, k;
int main() {
  string s;
  cin >> s;
  vector<int> num(5, 0);

  for (int j = 0; j < 8; j++) {
    char x = s[j];
    for (int i = 0; i < 5; i++) {
      if (x == str[i]) {
        num[i]++;
        if (i == 3) {
          if (b1 == -1) {
            b1 = j;
          } else {
            b2 = j;
          }
        } else if (i == 0) {
          k = j;
        } else if (i == 2) {
          if (r1 == -1) {
            r1 = j;
          } else {
            r2 = j;
          }
        }
        break;
      }
    }
  }

  bool f1 = (num[0] == 1) && (num[1] == 1) && (num[2] == 2) && (num[3] == 2) && (num[4] == 2);
  bool f2 = ((b1 ^ b2) & 1) == 1;
  bool f3 = (r1 < k) && (k < r2);
  bool f = f1 && f2 && f3;
  if (f) {
    cout << "Yes";
  } else {
    cout << "No";
  }

  return 0;
}