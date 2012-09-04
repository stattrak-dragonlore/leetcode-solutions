/*
Combination Sum
Given a set of candidate numbers (C) and a target number (T),
find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … ,ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7,
A solution set is:
[7]
[2, 2, 3]
*/

XXX

/*
#include <algorithm>
#include <vector>

using namespace std;

*/

/*
  solution(candidates, target) ==>   solution(candidates, target-a1) + solution(candidates-{a1}, target)
*/


void solve(vector<vector<int> >&result, vector<int> &picked, vector<int> &candidates, int from, int target)
{
	int n = candidates.size();
	if (n == from)
		return;

	if (candidates[from] > target)
		return;

	if (candidates[from] == target) {
		vector<int> tmp = picked;
		tmp.push_back(candidates[from]);
		result.push_back(tmp);
		return;
	}

	//pick the first
	picked.push_back(candidates[from]);
	solve(result, picked, candidates, from, target - candidates[from]);
	picked.pop_back();

	//don't pick the first
	solve(result, picked, candidates, from + 1, target);
}

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		sort(candidates.begin(), candidates.end());
		vector<vector<int> >result;
		vector<int> picked;
		solve(result, picked, candidates, 0, target);
		return result;
    }
};

/*

int main(int argc, char *argv[])
{
	Solution s;
	int c[] =  {2, 3, 7};
	vector<int> vc(c, c + sizeof(c)/sizeof(int));

	vector<vector<int> > result = s.combinationSum(vc, 7);
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) {
			printf("%d ", result[i][j]);
		}
		printf("\n");
	}
    return 0;
}
*/
