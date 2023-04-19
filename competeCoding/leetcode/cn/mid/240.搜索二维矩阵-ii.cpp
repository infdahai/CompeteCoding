/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start
class Solution {
 public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();
    int a = m - 1;
    int b = 0;
    while (a >= 0 && b < n) {
      int k = matrix[a][b] - target;
      if (k == 0) {
        return true;
      }
      if (k > 0) {
        a--;
      } else {
        b++;
      }
    }
    return false;
  }
};
// @lc code=end
