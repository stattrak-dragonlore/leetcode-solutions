/*
  Remove Duplicates from Sorted Array

Given a sorted array, remove the duplicates in place
such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array A = [1,1,2],

Your function should return length = 2, and A is now [1,2].

 */
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int p = 0;
        int last = 0;
        int first = 1;
        for (int i = 0; i < n; i++) {
            if (first) {
                A[p++] = A[i];
                first = 0;
                last = A[i];
            } else {
                if (A[i] != last) {
                    A[p++] = A[i];
                    last = A[i];
                }
            }
        }
        return p;
    }
};
