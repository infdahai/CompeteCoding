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
  while (is.find(",") != string::npos) {
    int found = is.find(",");
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

struct TreeNode {
  int v;
  TreeNode *l;
  TreeNode *r;
};

// #define TXT
int main() {
  fast_io;
#ifdef TXT
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif  // TXT

  string inputs;
  getline(cin, inputs);
  inputs = inputs.substr(11);
  inputs.erase(remove(inputs.begin(), inputs.end(), '['), inputs.end());
  inputs.erase(remove(inputs.begin(), inputs.end(), ']'), inputs.end());
  vec<int> nums = split(inputs);

  vec<pair<int, int>> ops;
  for (int i = 0; i < nums.size(); i++) {
    if (i % 2 == 0) {
      ops.pb(mp(nums[i], nums[i + 1]));
    }
  }

  TreeNode *head = new TreeNode{-1, nullptr, nullptr};

  vec<TreeNode *> first;
  first.pb(head);
  vec<vec<TreeNode *>> tree;
  tree.pb(first);

  for (int i = 0; i < ops.size(); i++) {
    int h = ops[i].first;
    int ind = ops[i].second;

    if (tree.size() <= h + 1) {
      vec<TreeNode *> temp;
      tree.pb(temp);
    }

    auto *temp = new TreeNode{i, nullptr, nullptr};
    tree[h + 1].pb(temp);

    if (tree[h][ind]->l == nullptr) {
      tree[h][ind]->l = tree[h + 1][tree[h + 1].size() - 1];
    } else if (tree[h][ind]->r == nullptr) {
      tree[h][ind]->r = tree[h + 1][tree[h + 1].size() - 1];
    }
  }
  vec<string> res;
  deque<TreeNode *> dq;
  dq.pb(tree[0][0]);

  while (dq.size() > 0) {
    auto *node = dq.front();
    dq.pop_front();
    if (node != nullptr) {
      res.pb(to_string(node->v));
      dq.pb(node->l);
      dq.pb(node->r);
    } else {
      res.pb("null");
    }
  }

  while (1) {
    if (res[res.size() - 1] == "null") {
      res.pop_back();
    } else
      break;
  }

  string os = "[";
  for (int i = 0; i < res.size(); i++) {
    os += res[i];
    if (i != res.size() - 1) {
      os += ",";
    }
  }

  os += ']';
  cout << os;

#ifdef TXT
  fclose(stdin);
  fclose(stdout);
#endif  // TXT
  return 0;
}