#include <bits/stdc++.h>

int n, m, x, y;

struct node {
  int l, r;
  mutable int v;
  node(int l1, int r1 = -1, int v1 = 0) : l(l1), r(r1), v(v1) {}
  bool operator<(const node &o) const { return l < o.l; }
};
using namespace std;
set<node> s;
using si = set<node>::iterator;

inline si split(int pos) {
  si it = s.lower_bound(node(pos));
  if (it != s.end() && it->l == pos)
    return it;
  --it;
  int l1 = it->l, r1 = it->r, v1 = it->v;
  s.erase(it);
  s.insert(node(l1, pos - 1, v1));
  return s.insert(node(pos, r1, v1)).first;
}

inline void asval(int l, int r, int val = 0) {
  si itr = split(r + 1), itl = split(l);
  s.erase(itl, itr);
  s.insert(node(l, r, val));
}

inline int query(int l, int r) {
  int res = 0;
  si itr = split(r + 1), itl = split(l);
  for (; itl != itr; ++itl)
    res += (itl->r - itl->l + 1) * (itl->v);
  return res;
}

int main() {
  scanf("%d%d", &n, &m);
  s.insert(node(0, n, 1));
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &x, &y);
    asval(x, y, 0);
  }
  int ans = query(0, n);
  printf("%d\n", ans);
  return 0;
}