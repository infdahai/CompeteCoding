/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    vector<vector<string>> res;

    auto arrayhash = [fn = hash<int>{}](const array<int, 26> &arr) -> size_t {
      return accumulate(arr.begin(), arr.end(), 0u, [&](size_t acc, int num) { return (acc << 1) ^ fn(num); });
    };

    unordered_map<array<int, 26>, vector<string>, decltype(arrayhash)> mp(0, arrayhash);
    for (auto &str : strs) {
      array<int, 26> cnts{};
      int len = str.length();
      for (int i = 0; i < len; i++) {
        cnts[str[i] - 'a']++;
      }
      mp[cnts].emplace_back(str);
    }
    for (auto it = mp.begin(); it != mp.end(); it++) {
      res.emplace_back(it->second);
    }

    return res;
  }
};
// @lc code=end
