/*
  Remove Duplicates from Sorted List
Given a sorted linked list, delete all
duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.

 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        int count = 0;
        ListNode *cur = head;
        ListNode *last = NULL;
        while (cur) {
            if (count == 0) {
                last = cur;
                cur = cur->next;
                count = 1;
            } else if (count == 1 && last->val == cur->val) {
                //delete cur
                last->next = cur->next;
                cur = cur->next;
            } else { //count == 1 && last->val != cur->val
                last = cur;
                cur = cur->next;
            }
        }
        return head;
    }
};
