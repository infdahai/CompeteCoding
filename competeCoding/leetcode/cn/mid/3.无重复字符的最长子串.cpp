/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    bool seen[255] = {false};
    int c = 0, j = 0;
    for (int i = 0; i < s.size(); i++) {
      while (seen[s[i]]) {
        seen[s[j]] = false;
        j++;
      }
      seen[s[i]] = true;
      c = max(c, i - j + 1);
    }
    return c;
  }
};
// @lc code=end
