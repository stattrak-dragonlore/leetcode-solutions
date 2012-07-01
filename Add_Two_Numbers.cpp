/*
Add Two Numbers
You are given two linked lists representing two non-negative numbers.
The digits are stored in reverse order and each of their nodes contain
 a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    	int carry = 0;
		ListNode *result = NULL;
		ListNode *current = NULL;

		while (l1 || l2) {
			int digit = 0;
			if (l1) {
				digit += l1->val;
			}
			if (l2) {
				digit += l2->val;
			}
			digit += carry;
			if (digit >= 10) {
				carry = 1;
				digit -= 10;
			} else {
				carry = 0;
			}

            ListNode *node = new ListNode(digit);

			if (!result) {
				result = node;
			} else {
				current->next = node;
			}
			current = node;

            if (l1)	 // don't miss this!
			    l1 = l1->next;
            if (l2)
			    l2 = l2->next;
		}

		if (carry) {
			current->next = new ListNode(1);
		}

		return result;
    }
};
