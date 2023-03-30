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

void calc(vec<vec<int>> &nodes, int ind, int n, vec<int> &list) {
  vec<int> node = nodes[ind];
  if (n == 0) {
    list.push_back(node[0]);
    return;
  }

  if (node.size() <= 1) {
    return;
  }

  for (int i = 1; i < node.size(); i++) {
    calc(nodes, node[i], n - 1, list);
  }
}

string get_res(vec<vec<int>> &nodes, vec<int> &sql) {
  int x = sql[0], y = sql[1];
  if (x < 0 || y < 0) {
    return "{}";
  }
  vec<int> list;
  calc(nodes, 0, x, list);
  if (y > list.size()) {
    return "{}";
  }
  return "{" + to_string(list[y]) + "}";
}

int main() {
  fast_io;

  int n;
  string inps;
  getline(cin, inps);
  n = stoi(inps);

  vec<vec<int>> nodes;
  for (int i = 0; i < n; i++) {
    getline(cin, inps);
    nodes.push_back(split(inps));
  }

  getline(cin, inps);
  vec<int> sql = split(inps);

  cout << get_res(nodes, sql);

  return 0;
}