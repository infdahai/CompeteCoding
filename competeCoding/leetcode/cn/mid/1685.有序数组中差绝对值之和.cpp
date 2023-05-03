/*
 * @lc app=leetcode.cn id=1685 lang=cpp
 *
 * [1685] 有序数组中差绝对值之和
 */

// @lc code=start
class Solution {
 public:
  vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n, 0);
    ans[0] = accumulate(nums.begin(), nums.end(), 0) - nums[0] * n;
    for (int i = 1; i < n; i++) {
      int d = nums[i] - nums[i - 1];
      ans[i] = ans[i - 1] - (n - 2 * i) * d;
    }
    return ans;
  }
};
// @lc code=end
