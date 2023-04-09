#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << "[debug]" #x << "=" << x << endl;
#define fast_io            \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0)
#define rep(i, a, b, c) for (int i = (a); i <= (b); i += (c))
// #define per(i, a, b, c) for (int i = (a); i >= (b); i -= (c))
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

// class UF {
//  public:
//   vec<int> item;
//   int cnt;
//   UF(int n) : cnt(n) {
//     item = vec<int>(n + 1, 0);
//     for (int i = 0; i < n; i++) item[i] = i;
//   }

//   int find(int x) {
//     if (x != item[x]) {
//       return (item[x] = find(item[x]));
//     }
//     return x;
//   }

//   void union_connect(int x, int y) {
//     int xitem = find(x);
//     int yitem = find(y);
//     if (xitem != yitem) {
//       item[yitem] = xitem;
//       cnt--;
//     }
//   }
// };

struct lnode {
  int v;
  int next;
  lnode(int v, int next) : v(v), next(next) {}
};

// inputs.erase(remove(inputs.begin(), inputs.end(), '['), inputs.end());

// struct per {
//   int id;
//   int cnt;
//   int day;
//   per(int id, int cnt, int day) : id(id), cnt(cnt), day(day) {}
// };

bool comp(const vec<int> &a, const vec<int> &b) {
  if (a[1] > b[1]) {
    return true;
  }
  if (a[1] == b[1]) {
    if (a[2] < b[2]) {
      return true;
    }
    if (a[2] == b[2]) {
      return a[0] < b[0];
    }
  }
  return false;
}

// #define TXT
int main() {
  fast_io;
#ifdef TXT
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif  // TXT

  int n;
  string inputs;
  getline(cin, inputs);
  n = stoi(inputs);
  getline(cin, inputs);
  vec<int> nums = split(inputs);

  vec<vec<int>> days;
  rep(i, 1, 30, 1) {
    vec<int> temp;
    getline(cin, inputs);
    temp = split(inputs);
    days.pb(temp);
  }
  // assert(days.size() == 30);

  map<int, vec<int>> ma;
  for (auto i = 0; i < days.size(); i++) {
    for (auto &v : days[i]) {
      if (ma.count(v)) {
        ma[v][1]++;
      } else {
        vec<int> b = {v, 1, i};
        ma[v] = b;
      }
    }
  }
  vec<vec<int>> res;
  for (auto &k : ma) {
    res.pb(k.second);
  }
  // debug(res.size());
  sort(res.begin(), res.end(), comp);

  if (res.size() < 5) {
    for (int i = 0; i < res.size(); i++) {
      cout << res[i][0] << " ";
    }
  } else {
    for (int i = 0; i < 5; i++) {
      cout << res[i][0] << " ";
    }
  }

#ifdef TXT
  fclose(stdin);
  fclose(stdout);
#endif  // TXT
  return 0;
}