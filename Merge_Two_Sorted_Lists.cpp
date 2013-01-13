/*
Merge Two Sorted Lists
Merge two sorted linked lists and return it as a new list.
The new list should be made by splicing together the nodes
of the first two lists.

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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *head = NULL;
        ListNode *cur;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                if (!head) {
                    head = l1;
                } else {
                    cur->next = l1;
                }
                cur = l1;
                l1 = l1->next;
            } else {
                if (!head) {
                    head = l2;
                } else {
                    cur->next = l2;
                }
                cur = l2;
                l2 = l2->next;
            }
        }

        while (l1) {
            if (!head) {
                head = l1;
            } else {
                cur->next = l1;
            }
            cur = l1;
            l1 = l1->next;
        }

        while (l2) {
            if (!head) {
                head = l2;
            } else {
                cur->next = l2;
            }
            cur = l2;
            l2 = l2->next;
        }
        return head;
    }
};
