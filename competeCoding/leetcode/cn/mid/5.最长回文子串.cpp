/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
 public:
  pair<int, int> comp(const string &s, int l, int r) {
    while (l >= 0 && r < s.size() && s[l] == s[r]) {
      l--, r++;
    }
    return {l + 1, r - 1};
  }

  string longestPalindrome(string s) {
    int begin = 0;
    int end = 0;
    for (int i = 0; i < s.size(); i++) {
      auto [l1, r1] = comp(s, i, i);
      auto [l2, r2] = comp(s, i, i + 1);
      if (r1 - l1 > end - begin) {
        begin = l1;
        end = r1;
      }
      if (r2 - l2 > end - begin) {
        begin = l2;
        end = r2;
      }
    }
    return s.substr(begin, end - begin + 1);
  }
};
// @lc code=end
