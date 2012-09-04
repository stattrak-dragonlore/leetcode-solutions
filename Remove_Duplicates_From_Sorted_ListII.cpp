/*
  Remove Duplicates from Sorted List II
Given a sorted linked list, delete all nodes
that have duplicate numbers, leaving only distinct
numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.

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
        int delete_cur = 0;
        ListNode *prev = NULL;
        ListNode *cur = head;
        ListNode *next;
        ListNode *new_head = NULL;

        while (cur) {
            next = cur->next;
            if (next && next->val == cur->val) {
                delete_cur = 1;
                //delete next
                cur->next = next->next;
            } else {
                if (delete_cur) {
                    delete_cur = 0;
                    //XX, prev == NULL
                    if (prev) {
                        prev->next = next;
                    }
                    cur = next;
                } else {
                    if (!new_head) {
                        new_head = cur;
                    }
                    prev = cur;
                    cur = next;
                }
            }
        }
        return new_head;
    }
};
