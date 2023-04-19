/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
 public:
  vector<int> searchRange(vector<int> &a, int tar) {
    vector<int> res;

    int l = 0, r = a.size() - 1;
    while (l <= r) {
      int m = l + (r - l) / 2;
      if (a[m] < tar) {
        l = m + 1;
      } else if (a[m] > tar) {
        r = m - 1;
      } else {
        check(a, m, tar);
        break;
      }
    }
    res.push_back(pos_l);
    res.push_back(pos_r);
    return res;
  }
  void check(vector<int> &nums, int &pos, int &target) {
    pos_l = pos_r = pos;
    while ((pos_l - 1) >= 0 && nums[pos_l - 1] == target) pos_l--;
    while ((pos_r + 1) < nums.size() && nums[pos_r + 1] == target) pos_r++;
  }
  int pos_l = -1, pos_r = -1;
};
// @lc code=end
