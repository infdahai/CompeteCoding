#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n, k;
int l;
const int maxn = 300005;
int a[maxn];
int son[maxn * 30][2], idx;
#define _rep(i, a, b) for (int i = (a); i <= (b); i++)
unordered_map<int, vector<int>> mp;
unordered_map<int, int> idmp;
vector<int> res;
int get(int tp) {
  int temp = 0;
  while (tp) {
    tp >>= 1;
    temp++;
  }
  return temp;
}
void insert(int x) {
  int p = 0;
  for (int i = 29; i >= 0; i--) {
    int u = x >> i & 1;
    if (!son[p][u])
      son[p][u] = ++idx;
    p = son[p][u];
  }
}
int query(int x) {
  int p = 0;
  int ans = 0;
  for (int i = 29; i >= 0; i--) {
    int u = x >> i & 1;
    if (son[p][u ^ 1]) {
      ans = (ans << 1) + (u ^ 1);
      p = son[p][u ^ 1];
    } else {
      ans = (ans << 1) + u;
      p = son[p][u];
    }
  }
  return ans;
}
int main() {
  scanf("%d%d", &n, &k);
  int m = get(k);
  _rep(i, 1, n) {
    scanf("%d", &a[i]);
    int x = a[i] >> m;
    mp[x].push_back(a[i]);
    idmp[a[i]] = i;
  }
  if (k == 0) {
    printf("%d\n", n);
    _rep(i, 1, n) printf("%d ", i);
    return 0;
  }
  for (auto &[key, v] : mp) {
    memset(son, 0, sizeof(int) * 2 * (idx+3));
    idx = 0;
    int l = -1, r = -1;
    int gg = -1;
    for (auto x : v) {
      gg = idmp[x];
      insert(x);
      int t = query(x);
      if ((t ^ x) >= k) {
        l = idmp[x], r = idmp[t];
        break;
      }
    }
    if (l > 0 && r > 0) {
      res.push_back(l);
      res.push_back(r);
    } else if (gg > 0) {
      res.push_back(gg);
    }
  }
  if (res.size() < 2)
    puts("-1");
  else {
    printf("%ld\n", res.size());
    _rep(i, 1, res.size()) printf("%d ", res[i - 1]);
  }

  return 0;
}