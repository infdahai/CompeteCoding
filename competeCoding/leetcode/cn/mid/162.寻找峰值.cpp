/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 */

// @lc code=start
class Solution {
 public:
  int findPeakElement(vector<int> &nums) { return bin(nums, 0, nums.size() - 1); }

  int bin(vector<int> &a, int l, int r) {
    while (l < r) {
      int m = l + (r - l) / 2;
      if (a[m] > a[m + 1]) {
        r = m;
      } else {
        l = m + 1;
      }
    }
    return l;
  }
};
// @lc code=end
