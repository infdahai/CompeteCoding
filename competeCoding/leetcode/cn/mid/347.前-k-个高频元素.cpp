/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
class Solution {
 public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    unordered_map<int, int> t;
    for (int n : nums) {
      t[n]++;
    }
    vector<pair<int, int>> temp;
    //通过vector来进行排序
    for (auto it = t.begin(); it != t.end(); it++) {
      temp.push_back({it->first, it->second});
    }
    sort(temp.begin(), temp.end(), cmp);
    vector<int> res;
    //得到前k个最大的元素
    for (int i = 0; i < k; i++) {
      res.push_back(temp[i].first);
    }
    return res;
  }

  static bool cmp(pair<int, int> &t1, pair<int, int> &t2) { return t1.second > t2.second; }
};
// @lc code=end
