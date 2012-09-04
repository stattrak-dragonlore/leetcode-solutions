/*
Remove Duplicates from Sorted Array II
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array A = [1,1,1,2,2,3],

Your function should return length = 5,
and A is now [1,1,2,2,3].

*/

class Solution {
public:
    int removeDuplicates(int A[], int n) {
		int count = 0;
		int p = 0;
		for (int i = 0; i < n; i++) {
			if (count == 0) {
				A[p++] = A[i];
				count = 1;
			} else if (count == 1) {
				if (A[p-1] == A[i]) {
					count = 2;
				} // else count = 1;
				A[p++] = A[i];

			} else { // count=2
				if (A[p-1] != A[i]) {
					A[p++] = A[i];
					count = 1;
				}
			}
		}
		return p;
    }
};
