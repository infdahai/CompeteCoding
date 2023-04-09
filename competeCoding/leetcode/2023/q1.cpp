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

// inputs.erase(remove(inputs.begin(), inputs.end(), '['), inputs.end());

struct tmp2 {
  bool operator()(vec<int> &a, vec<int> &b) { return a[0] > b[0]; }
};

int solve(vec<vec<int>> &ranges) {
  int machines = 0;
  priority_queue<vec<int>, vec<vec<int>>, tmp2> pq;
  sort(ranges.begin(), ranges.end(), [](auto &a, auto &b) { return a[0] < b[0]; });

  int res = 0;
  for (int i = 0; i < ranges.size(); i++) {
    while (pq.size() > 0) {
      if (pq.top()[0] <= ranges[i][0]) {
        machines -= pq.top()[1];
        pq.pop();
      } else {
        break;
      }
    }
    pq.push(vec<int>{ranges[i][1], ranges[i][2]});
    machines += ranges[i][2];
    if (res < machines) {
      res = machines;
    }
  }
  return res;
}

// #define TXT
int main() {
  fast_io;
#ifdef TXT
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif  // TXT

  int task = 0;
  cin >> task;
  vec<vec<int>> ranges;
  rep(i, 1, task, 1) {
    int a, b, c;
    cin >> a >> b >> c;
    vec<int> temp;
    temp.pb(a);
    temp.pb(b);
    temp.pb(c);
    ranges.pb(temp);
  }

  cout << solve(ranges);

#ifdef TXT
  fclose(stdin);
  fclose(stdout);
#endif  // TXT
  return 0;
}