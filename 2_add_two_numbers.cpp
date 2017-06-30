//You are given two non-empty linked lists representing two non-negative integers.
//The digits are stored in reverse order and each of their nodes contain a single digit.
//Add the two numbers and return it as a linked list.
//
//You may assume the two numbers do not contain any leading zero, except the number 0 itself.
//
//Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
//  Output: 7 -> 0 -> 8

class Solution {
  public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      int mark = 0;
      ListNode* ans = l1;
      while (l1->next != NULL && l2->next != NULL) {
        l1->val = l1->val + l2->val + mark;
        mark = l1->val/10;
        l1->val = l1->val%10;

        l1 = l1->next;
        l2 = l2->next;
      }
      if (l1->next == NULL) {
        l1->next = l2->next;
      }
      l1->val = l1->val + l2->val + mark;
      mark = l1->val/10;
      l1->val %= 10;
      while (l1->next != NULL) {
        l1 = l1->next;

        l1->val += mark;
        mark = l1->val/10;
        l1->val %= 10;
      }
      if (mark != 0) l1->next = l2, l2->val = mark, l2->next = NULL;
      return ans;
    }
};
