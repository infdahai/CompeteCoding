/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
 public:
  // double pointer
  vector<vector<int>> threeSum(vector<int> &nums) {
    int sz = nums.size();
    if (sz < 3) {
      return {};
    }
    vector<vector<int>> res;
    res.reserve(sz);
    sort(nums.begin(), nums.end());
    for (int i = 0; i < sz - 2; i++) {
      if (nums[i] > 0) {
        return res;
      }
      if (i >= 1 && nums[i] == nums[i - 1]) {
        continue;
      }
      int l = i + 1;
      int r = sz - 1;
      int t = -nums[i];
      while (l < r) {
        int a = nums[l], b = nums[r];
        if (a + b == t) {
          res.push_back({nums[i], a, b});
          while (l < r && a == nums[l + 1]) {
            l++;
          }
          while (l < r && b == nums[r - 1]) {
            r--;
          }
          l++, r--;
        } else if (a + b > t) {
          r--;
        } else {
          l++;
        }
      }
    }
    return res;
  }
};
// @lc code=end
