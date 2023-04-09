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

// #define TXT
int main() {
  fast_io;
#ifdef TXT
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif  // TXT

  string inputs;
  cin >> inputs;
  map<char, int> char_cnt;
  for (auto x : inputs) {
    if (char_cnt.count(x)) {
      char_cnt[x] += 1;
    } else {
      char_cnt[x] = 1;
    }
  }

  if (char_cnt['W'] == char_cnt['A'] && char_cnt['W'] == char_cnt['S'] && char_cnt['W'] == char_cnt['D']) {
    cout << 0;
    return 0;
  }

  int l = 0, r = 0, len = 0;
  int res = inputs.size();
  int max_num = 0;
  int free_num = 0;

  char_cnt[inputs[0]]--;
  while (1) {
    max_num = max(max(max(char_cnt['W'], char_cnt['A']), char_cnt['S']), char_cnt['D']);
    len = r - l + 1;
    free_num = len - ((max_num - char_cnt['W']) + (max_num - char_cnt['A']) + (max_num - char_cnt['S']) +
                      (max_num - char_cnt['D']));
    if (free_num >= 0 && free_num % 4 == 0) {
      if (len < res) {
        res = len;
      }
      char_cnt[inputs[l]]++;
      l++;
    } else {
      r++;
      char_cnt[inputs[r]]--;
    }
    if (r >= inputs.size()) {
      break;
    }
  }
  cout << res;

#ifdef TXT
  fclose(stdin);
  fclose(stdout);
#endif  // TXT
  return 0;
}