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
#define vec vector
using ll = long long;
#define INF 0x3f3f3f3f

inline int gcd(int a, int b) { return b > 0 ? gcd(b, a % b) : a; }

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

class Solution {
 public:
  bitset<9> getPossibleStatus(int x, int y) {
    return ~(rows[x] | cols[y] | cells[x / 3][y / 3]);
  }

  void fillNum(int x, int y, int n, bool fillFlag) {
    rows[x][n] = (fillFlag) ? 1 : 0;
    cols[y][n] = (fillFlag) ? 1 : 0;
    cells[x / 3][y / 3][n] = (fillFlag) ? 1 : 0;
  }

  vector<int> getNext(vector<vector<char>>& board) {}

  bool dfs(vector<vector<char>>& board, int cnt) {
    if (cnt == 0) return true;

    auto next = getNext();
    return false;
  }

  void solveSudoku(vector<vector<char>>& board) {
    rows = vector<bitset<9>>(9, bitset<9>());
    cols = vector<bitset<9>>(9, bitset<9>());
    cells = vector<vector<bitset<9>>>(3, vector<bitset<9>>(3, bitset<9>()));

    int cnt = 0;
    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[i].size(); j++) {
        cnt += (board[i][j] == '.');
        if (board[i][j] == '.') continue;
        int n = board[i][j] - '1';
        rows[i] |= (1 << n);
        cols[j] |= (1 << n);
        cells[i / 3][j / 3] |= (1 << n);
      }
    }
  }

 private:
  vector<bitset<9>> rows;
  vector<bitset<9>> cols;
  vector<vector<bitset<9>>> cells;
};

// #define TXT
int main() {
  fast_io;
#ifdef TXT
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif  // TXT

#ifdef TXT
  fclose(stdin);
  fclose(stdout);
#endif  // TXT
  return 0;
}