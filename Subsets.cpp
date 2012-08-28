/*
Subsets
Given a set of distinct integers, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
		sort(S.begin(), S.end());
		int n = S.size();
		vector<vector<int> > result;
		for (int i = 0; i < (1 << n); i++) {
			vector<int> s;
			for (int j = 0; j < n; j++) {
				if ((i >> j) & 1) {
					s.push_back(S[j]);
				}
			}
			result.push_back(s);
		}
		return result;
    }
};
