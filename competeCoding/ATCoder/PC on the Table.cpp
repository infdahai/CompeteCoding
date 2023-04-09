#include <bits/stdc++.h>

using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> s;
  for (int i = 0; i < h; i++) {
    string s1;
    cin >> s1;
    s.emplace_back(s1);
  }

  for (auto &s1 : s) {
    bool t = false;
    for (int j = 0; j < w; j++) {
      if (t == true) {
        if (s1[j] == 'T') {
          s1[j - 1] = 'P';
          s1[j] = 'C';
          t = false;
          continue;
        }
      }
      if (s1[j] == 'T') {
        t = true;
      } else {
        t = false;
      }
    }
  }
  for (auto &s1 : s) {
    cout << s1 << '\n';
  }
  return 0;
}