#include <bits/stdc++.h>

using namespace std;
int n, m;
int i, f, k[5001], s[5001], sub[5001];
bool cmp(int a, int b) {
  if (s[a] == s[b])
    return k[a] < k[b];
  else
    return s[a] > s[b];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (i = 1; i <= n; i++)
    cin >> k[sub[i] = i] >> s[i];
  sort(sub + 1, sub + n + 1, cmp);
  f = s[sub[int(m * 1.5)]];
  for (i = 1; s[sub[i]] >= f; i++)
    ;
  cout << f << " " << i - 1 << endl;
  for (i = 1; s[sub[i]] >= f; i++)
    cout << k[sub[i]] << " " << s[sub[i]] << "\n";

  return 0;
}