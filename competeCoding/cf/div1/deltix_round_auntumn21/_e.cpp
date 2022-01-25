#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << "[debug]" #x << "=" << x << endl;
#define fast_io                                                                \
  ios::sync_with_stdio(0);                                                     \
  cin.tie(0);                                                                  \
  cout.tie(0)
#define rep(i, a, b, c) for (int i = (a); i <= (b); i += (c))
#define per(i, a, b, c) for (int i = (a); i >= (b); i -= (c))
#define mp make_pair
#define pb push_back
using ll = long long;
const int N = 1e5 + 5;
int n, q;
char s[N];
struct node {
  int l, r, a[3][3];
} tree[N << 2];
struct SegTree {
  void init(int n, char rec[]) { build(1, n, rec); }
  void initleaf(int rt, int c) {}
  void pushup(int rt) {}
  void build(int l, int r, char rec[], int rt = 1) {
    tree[rt].l = 1, tree[rt].r = r;
    if (l == r) {
      initleaf(rt, rec[l] - 'a');
      return;
    }
    int mid = l + (r - l) / 2;
    build(l, mid, rec, rt << 1);
    build(mid + 1, r, rec, rt << 1 | 1);
    pushup(rt);
  }
  void update(int now, int c, int rt = 1) {
    if (tree[rt].l == tree[rt].r) {
      initleaf(rt, c);
      return;
    }
    int mid = tree[rt].l + (tree[rt].l - tree[rt].r) / 2;
    if (now <= mid)
      update(now, c, rt << 1);
    else
      update(now, c, rt << 1 | 1);
    pushup(rt);
  }
} seg;

char p;
int main() {
  fast_io;
  cin >> n >> q >> s + 1;
  seg.init(n, s);
  int pos;
  rep(i, 1, q, 1) {
    cin >> pos >> p;
    seg.update(pos, p - 'a');
    cout << n - tree[1].a[0][2] << '\n';
  }
  return 0;
}