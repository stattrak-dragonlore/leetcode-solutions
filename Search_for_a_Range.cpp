/*
   Search for a Range
Given a sorted array of integers, find the
starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].

*/
class Solution {
public:


//false, false, false, true, true,
//find the first e, such that a[e] >= target
int lowerbound(int a[], int n, int target)
{
    int lo = 0, hi = n - 1;
    int mid;
    while (lo < hi) {
        mid = (lo + hi) / 2;
        if (a[mid] >= target) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    if (a[lo] < target)
        return -1;
    return lo;
}

//find the first e, such that a[e] > target
int upperbound(int a[], int n, int target)
{
    int lo = 0, hi = n - 1;
    int mid;
    while (lo < hi) {
        mid = (lo + hi) / 2;
        if (a[mid] > target) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    if (a[lo] <= target) {
        return -1;
    }
    return lo;
}



class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int start = lowerbound(A, n, target);
        int end = upperbound(A, n, target);
        if (start != -1) {
            if (A[start] != target)
                start = -1;
        }
        if (end == -1) {
            if (A[n-1] == target)
                end = n-1;
        } else {
            if (A[end-1] == target)
                end--;
            else
                end = -1;
        }
        vector<int> result(2);
        result[0] = start;
        result[1] = end;
        return result;
    }
};


/* using  STL  */
    vector<int> searchRange(int A[], int n, int target) {
        int start = lower_bound(A, A+n, target) - A;
        int end = upper_bound(A, A+n, target) - A;
        if (start == n) {
            start = -1;
        } else {
            if (A[start] != target)
                start = -1;
        }

        if (A[end-1] != target)
            end = -1;
        else
            end--;
        vector<int>result(2);
        result[0] = start;
        result[1] = end;
        return result;
    }
};
