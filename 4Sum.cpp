/*
4Sum
Given an array S of n integers, are there elements a, b, c, and d in S
such that a + b + c + d = target? Find all unique quadruplets in the
array which gives the sum of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.
    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)

Solution:
    The O(n^3) algorithm is almost the same as the 3Sum.

*/

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

		sort(num.begin(), num.end());
		set<vector<int> >rs;
		int n = num.size();
		for (int i = 0; i < n - 3; i++) {
			for (int j = i + 1; j < n - 2; j++) {
				int p = j + 1;
				int q = n - 1;

				while (p < q) {
					int sum = num[i] + num[j] + num[p] + num[q];
					if (sum == target) {
						vector<int> tmp(4);
						tmp[0] = num[i];
						tmp[1] = num[j];
						tmp[2] = num[p];
						tmp[3] = num[q];
						rs.insert(tmp);
						p++;
						q--;
					} else if (sum < target) {
						p++;
					} else {
						q--;
					}
				}
			}
		}
		vector<vector<int> > result(rs.begin(), rs.end());
		return result;
    }
};
