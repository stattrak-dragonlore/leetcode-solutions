/*
  Subsets II
Given a collection of integers that might contain duplicates, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
		sort(S.begin(), S.end());
		set<vector<int> > rs;
		int n = S.size();
		vector<vector<int> > result;
		for (int i = 0; i < (1 << n); i++) {
			vector<int> s;
			for (int j = 0; j < n; j++) {
				if ((i >> j) & 1) {
					s.push_back(S[j]);
				}
			}
			rs.insert(s);
		}
		vector<vector<int> > result(rs.begin(), rs.end());
		return result;
    }
};
