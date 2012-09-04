/*
   Maximum Subarray
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.

*/
class Solution {
public:
    int maxSubArray(int A[], int n) {
        int tmp_sum = 0;
        int max_sum = INT_MIN;
        for (int i = 0; i < n; i++) {
            tmp_sum += A[i];
            max_sum = max(max_sum, tmp_sum);
            tmp_sum = max(tmp_sum, 0);
        }
        return max_sum;
    }
};
