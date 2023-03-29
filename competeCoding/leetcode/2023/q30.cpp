#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << "[debug]" #x << "=" << (x) << endl;
#define fast_io            \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0)
#define rep(i, a, b, c) for (int i = (a); i <= (b); i += (c))
#define per(i, a, b, c) for (int i = (a); i >= (b); i -= (c))
#define endl "\n"
#define mp make_pair
#define pb push_back
#define vec vector
using ll = long long;

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

vec<vec<int>> dirs = {{-1, -1}, {0, -1}, {1, -1}, {-1, 0},
                      {1, 0},   {-1, 1}, {0, 1},  {1, 1}};

void bfs(int n, int m, vec<vec<int>>& matrix, vec<vec<int>>& flip) {
  if (flip.size() == 0) {
    return;
  }
  vec<int> pos = flip[0];

  for (auto d : dirs) {
    int nx = pos[0] + d[0];
    int ny = pos[1] + d[1];
    if (nx >= 0 && nx < n && ny > 0 && ny < m) {
      if (matrix[nx][ny] == 1) {
        matrix[nx][ny] = 1;
        vec<int> newlist;
        newlist.pb(nx);
        newlist.pb(ny);
        flip.pb(newlist);
      }
    }
  }
  flip.erase(flip.begin());
  bfs(n, m, matrix, flip);
}

int main() {
  fast_io;

  int n, m;
  string sss;
  getline(cin, sss);
  vec<int> ss_ = split(sss);
  n = ss_[0];
  m = ss_[1];
  int c;

  vector<vector<int>> matrix;

  for (int i = 0; i < n; i++) {
    string ss;
    getline(cin, ss);
    matrix.push_back(split(ss));
  }

  int res = 0;

  for (int x = 0; x < matrix.size(); x++) {
    for (int y = 0; y < matrix[0].size(); y++) {
      if (matrix[x][y] == 1) {
        res++;
        vec<vec<int>> flip;
        vec<int> temp_list;
        temp_list.pb(x);
        temp_list.pb(y);
        flip.pb(temp_list);
        bfs(n, m, matrix, flip);
      }
    }
  }

  cout << res;

  return 0;
}