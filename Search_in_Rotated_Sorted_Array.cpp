/*
  Search in Rotated Sorted Array
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index,
otherwise return -1.

You may assume no duplicate exists in the array.

 */
class Solution {
public:
    int search(int A[], int n, int target) {
        //binary search the index of max elment first
        int left = 0, right = n - 1;
        int max_index = 0;
        while (1) {
            if (right - left < 2) {
                if (A[left] > A[right]) {
                    max_index = left;
                } else {
                    max_index = right;
                }
                break;
            }

            int mid = (left + right) / 2;
            if (A[mid] > A[right]) {
                left = mid;
            } else if (A[mid] > A[left]) {
                max_index = right;
                break;
            } else {
                right = mid - 1;
            }
        }

        int t = lower_bound(A, A + max_index + 1, target) - A;
        int t2 = lower_bound(A + max_index + 1, A + n, target) - A;
        if (t != n && A[t] == target)
            return t;
        if (t2 != n && A[t2] == target)
            return t2;
        return -1;
    }
};
