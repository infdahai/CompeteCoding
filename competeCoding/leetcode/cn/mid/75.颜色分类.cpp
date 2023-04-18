/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
class Solution {
 public:
  void sortColors(vector<int> &nums) {
    int l = 0;
    int r = nums.size() - 1;
    int ind = 0;
    while (ind <= r) {
      int a = nums[ind];
      if (a == 0) {
        swap1(nums, l, ind);
        l++;
        ind++;
      } else if (a == 1) {
        ind++;
      } else if (a == 2) {
        swap1(nums, r, ind);
        r--;
      }
    }
  }
  void swap1(vector<int> &nums, int i, int j) {
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
  }
};
// @lc code=end
