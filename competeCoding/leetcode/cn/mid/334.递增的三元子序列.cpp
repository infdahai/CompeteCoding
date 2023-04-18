/*
 * @lc app=leetcode.cn id=334 lang=cpp
 *
 * [334] 递增的三元子序列
 */

// @lc code=start
class Solution {
 public:
  bool increasingTriplet(vector<int> &nums) {
    // const int maxnum = 2 ^ 31 - 1;
    int small = INT_MAX, mid = INT_MAX;
    for (int a : nums) {
      if (a <= small) {
        small = a;
      } else if (a <= mid) {
        mid = a;
      } else {
        return true;
      }
    }
    return false;
  }
};
// @lc code=end
