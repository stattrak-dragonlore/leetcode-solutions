/*
   Merge k Sorted Lists
Merge k sorted linked lists and return it as one sorted list.
Analyze and describe its complexity.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <set>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef struct ListNode {
   int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
  } ListNode;

class nodecmp {
public:
    bool operator() (const ListNode  *a, const ListNode *b) const
		{return a->val > b->val;}
};

//min heap
typedef struct heapq {
	ListNode **q;
	int size;
} heapq;

void heapify(heapq *Q, int sink)
{
	int size = Q->size;
	ListNode **q = Q->q;
	if (sink >= size)
		return;
	while (1) {
		int next = -1;
		int min = q[sink]->val;
		int l = sink * 2 + 1;
		if (l < size) {
			if (q[l]->val < min) {
				min = q[l]->val;
				next = l;
			}
		}

		int r = sink * 2 + 2;
		if (r < size) {
			if (q[r]->val < min) {
				min = q[r]->val;
				next = r;
			}
		}
		if (next == -1)
			break;
		swap(q[next], q[sink]);
		sink = next;
	}
}

void heapq_pop(heapq *q)
{
	if (q->size == 0) {
		//raise
	}
	q->q[0] = q->q[q->size-1];
	q->size--;
	heapify(q, 0);
}

void heapq_push(heapq *q, ListNode *e)
{
	q->q[q->size] = e;
	q->size++;
	//move e to top if neccessary
	int up = q->size-1;

	while (up) {
		int next = -1;
		int parent = (up - 1) / 2;
		if (q->q[up]->val >= q->q[parent]->val) {
				break;
		} else {
			swap(q->q[up], q->q[parent]);
			up = parent;
		}
	}
}


class Solution {
public:
	ListNode *mergeKLists(vector<ListNode *> &lists) {
		heapq q;
		int k = lists.size();
		q.size = 0;
		q.q = (ListNode **)malloc(sizeof(ListNode *) * k);
		for (int i = 0; i < k; i++) {
			if (lists[i]) {
				heapq_push(&q, lists[i]);
			}
		}
		ListNode *cur;
		ListNode *head = NULL;
		while (q.size > 0) {
			ListNode *t = q.q[0];
			if (!head) {
				head = t;
				cur = t;
			} else {
				cur->next = t;
				cur = t;
			}
			heapq_pop(&q);
			if (t->next) {
				heapq_push(&q, t->next);
			}
		}
		return head;
	}

    ListNode *mergeKLists2(vector<ListNode *> &lists) {
		int k = lists.size();
		priority_queue<ListNode *, vector<ListNode*>, nodecmp> q;
		for (int i = 0; i < k; i++) {
			if (lists[i] != NULL) {
				q.push(lists[i]);
			}
		}
		ListNode *head = NULL;
		ListNode *cur;
		while (!q.empty()) {
			ListNode *t  = q.top();
			if (!head) {
				head = t;
				cur = t;
			} else {
				cur->next = t;
				cur = t;
			}
			q.pop();
			if (t->next) {
				q.push(t->next);
			}
		}
		return head;
    }
};

void printlist(ListNode *n)
{
	while (n) {
		cout << n->val << " -> ";
		n= n->next;
	}
	cout << endl;
}

int main(int argc, char *argv[])
{

	vector<ListNode *> x;
	ListNode *n1 = new ListNode(-2);
	ListNode *n2 = new ListNode(-3);
	ListNode *n3 = new ListNode(-2);
	ListNode *n4 = new ListNode(-1);
	n1->next = NULL;
	n2->next = n3;
	n3->next = n4;
	n4->next = NULL;
	x.push_back(n1);
	x.push_back(n2);
	x.push_back(NULL);
	Solution s;
	ListNode *head = s.mergeKLists(x);
	printlist(head);

    return 0;
}
