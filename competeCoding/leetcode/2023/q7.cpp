#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << "[debug]" #x << "=" << x << endl;
#define fast_io            \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0)
#define rep(i, a, b, c) for (int i = (a); i <= (b); i += (c))
#define per(i, a, b, c) for (int i = (a); i >= (b); i -= (c))
#define endl "\n"
#define mp make_pair
#define pb push_back
using ll = long long;

struct lnode {
  int val;
  int next;
  lnode(int v, int n) : val(v), next(n) {}
};

int main() {
  fast_io;

  int n, head_addr;

  cin >> head_addr >> n;
  map<int, lnode*> m;
  for (int i = 0; i < n; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    m[a] = new lnode(b, c);
  }

  lnode* head = m[head_addr];
  lnode* cur = head;
  int size = 1;
  while (cur->next != -1) {
    size++;
    cur = m[cur->next];
  }

  if (size % 2 == 1) {
    size = size / 2 + 1;
  } else {
    size = size / 2;
  }

  int cnt = 0;
  cur = head;
  while (cnt != size) {
    cur = m[cur->next];
    cnt++;
  }
  cout << cur->val << endl;
  return 0;
}