#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << "[debug]" #x << "=" << x << endl;
#define fast_io            \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0)
#define rep(i, a, b, c) for (int i = (a); i <= (b); i += (c))
#define per(i, a, b, c) for (int i = (a); i >= (b); i -= (c))
// #define endl "\n"
#define mp make_pair
#define pb push_back
#define vec std::vector
using ll = long long;
#define INF 0x3f3f3f3f

vec<string> split_str(string is) {
  vec<string> v;
  while (is.find(" ") != string::npos) {
    int found = is.find(" ");
    v.push_back(is.substr(0, found));
    is = is.substr(found + 1);
  }
  v.push_back(is);
  return v;
}

vec<int> split(string is) {
  vec<int> v;
  while (is.find(" ") != string::npos) {
    int found = is.find(" ");
    v.push_back(stoi(is.substr(0, found)));
    is = is.substr(found + 1);
  }
  v.push_back(stoi(is));
  return v;
}

class UF {
 public:
  vec<int> item;
  int cnt;
  UF(int n) : cnt(n) {
    item = vec<int>(n + 1, 0);
    for (int i = 0; i < n; i++) item[i] = i;
  }

  int find(int x) {
    if (x != item[x]) {
      return (item[x] = find(item[x]));
    }
    return x;
  }

  void union_connect(int x, int y) {
    int xitem = find(x);
    int yitem = find(y);
    if (xitem != yitem) {
      item[yitem] = xitem;
      cnt--;
    }
  }
};

struct lnode {
  int v;
  int next;
  lnode(int v, int next) : v(v), next(next) {}
};

// inputs.erase(remove(inputs.begin(), inputs.end(), '['), inputs.end());

bool comp(pair<int, int> &a, pair<int, int> &b) {
  if (a.first < b.first) {
    return true;
  } else if (a.first > b.first) {
    return false;
  }
  return a.second < b.second;
}

pair<int, int> ab(int p, int m, int n) {
  int cnt = 0;
  while (m > 0) {
    if (p < 100) {
      break;
    }
    p -= (p / 100 * 10);
    cnt++;
    m--;
  }
  p *= 0.92;
  cnt++;
  return mp(p, cnt);
}

pair<int, int> ac(int p, int m, int k) {
  int cnt = 0;
  while (m > 0) {
    if (p < 100) {
      break;
    }
    p -= (p / 100 * 10);
    cnt++;
    m--;
  }
  for (int i = 0; i < k; i++) {
    p -= 5;
    cnt += 1;
    if (p < 0) {
      p += 5;
      cnt--;
      break;
    }
  }
  return mp(p, cnt);
}

pair<int, int> ba(int p, int m, int n) {
  int cnt = 1;
  p *= 0.92;
  while (m > 0) {
    if (p < 100) {
      break;
    }
    p -= (p / 100 * 10);
    cnt++;
    m--;
  }
  return mp(p, cnt);
}

pair<int, int> bc(int p, int n, int k) {
  int cnt = 1;
  p *= 0.92;
  for (int i = 0; i < k; i++) {
    p -= 5;
    cnt += 1;
    if (p < 0) {
      p += 5;
      cnt--;
      break;
    }
  }
  return mp(p, cnt);
}

// #define TXT
int main() {
  fast_io;
#ifdef TXT
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif  // TXT

  int m, n, k;
  cin >> m >> n >> k;
  int x;
  cin >> x;
  for (int i = 0; i < x; i++) {
    int a;
    cin >> a;
    vec<pair<int, int>> res;

    res.pb(ab(a, m, n));
    res.pb(ac(a, m, k));
    res.pb(ba(a, m, n));
    res.pb(bc(a, m, k));

    sort(res.begin(), res.end(), comp);
    cout << res[0].first << " " << res[0].second << endl;
  }

#ifdef TXT
  fclose(stdin);
  fclose(stdout);
#endif  // TXT
  return 0;
}