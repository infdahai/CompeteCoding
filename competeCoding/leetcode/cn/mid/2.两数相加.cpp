/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
 public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    int c = 0;
    int a = l1->val, b = l2->val;
    auto *dummy = new ListNode(0);
    auto *prev = dummy;
    while (l1 != nullptr || l2 != nullptr || c != 0) {
      int sum = c;
      if (l1 != nullptr) {
        sum += l1->val;
        l1 = l1->next;
      }
      if (l2 != nullptr) {
        sum += l2->val;
        l2 = l2->next;
      }

      prev->next = new ListNode(sum % 10);
      c = sum / 10;
      prev = prev->next;
    }
    return dummy->next;
  }
};
// @lc code=end
