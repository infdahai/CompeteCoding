/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> mer;
    for (int i = 0; i < intervals.size(); i++) {
      int l = intervals[i][0], r = intervals[i][1];
      if (mer.empty() || mer.back()[1] < l) {
        mer.push_back({l, r});
      } else {
        mer.back()[1] = max(mer.back()[1], r);
      }
    }
    return mer;
  }
};
// @lc code=end
