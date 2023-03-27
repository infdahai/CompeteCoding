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

struct comp {
  bool operator()(vector<int> a, vector<int> b) { return a[0] > b[0]; }
};

int compute(vector<vector<int>> &ranges) {
  priority_queue<vector<int>, vector<vector<int>>, comp> pq;
  sort(ranges.begin(), ranges.end(),
       [](auto a, auto b) { return a[0] < b[0]; });
  int res = 0;
  int temp_val = 0;
  for (int i = 0; i < ranges.size(); i++) {
    while (!pq.empty()) {
      if (pq.top()[0] < ranges[i][0]) {
        temp_val -= pq.top()[1];
        pq.pop();
      } else {
        break;
      }
    }
    pq.emplace(vector<int>{ranges[i][1], ranges[i][2]});
    temp_val += ranges[i][2];
    if (temp_val > res) {
      res = temp_val;
    }
  }
  return res;
}

int main() {
  fast_io;

  int n = 0;
  cin >> n;

  vector<vector<int>> ranges;
  rep(i, 1, n, 1) {
    int a, b, c;
    cin >> a >> b >> c;
    vector<int> temp{a, b, c};
    ranges.emplace_back(temp);
  }
  cout << compute(ranges) << endl;
  return 0;
}