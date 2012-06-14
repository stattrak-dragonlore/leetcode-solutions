/*
Given an array S of n integers, find three integers in S such that the sum is
closest to a given number, target. Return the sum of the three integers.
You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

*/

/*
   O(n^2 * lgn) solution
   1. sort the array
   2. test all i, j, then binary search (target-i-j)

   The O(n^2) algorithm to 3Sum problem still works.
*/

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        int n = num.size();
        int best = INT_MAX;
        int result = 0;
        for (int i = 0; i < n - 2; i++) {
            int j = i + 1;
            int k = n - 1;
            while (j < k) {
                int sum = num[i] + num[j] + num[k];
                if (sum == target) {
                    return sum;
                } else if (sum < target) {
                    if (target - sum < best) {
                        best = target - sum;
                        result = sum;
                    }
                    j++;
                } else if (sum > target) {
                    if (sum - target < best) {
                        best = sum - target;
                        result = sum;
                    }
                    k--;
                }
            }
        }
        return result;
    }
};
