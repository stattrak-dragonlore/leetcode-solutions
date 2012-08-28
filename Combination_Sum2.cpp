/*
Combination Sum II
Given a collection of candidate numbers (C) and a target number (T),
find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … ,ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8,
A solution set is:
[1, 7]
[1, 2, 5]
[2, 6]
[1, 1, 6]

*/

#include <algorithm>
#include <vector>
#include <set>

using namespace std;


void solve(vector<int> &picked, vector<int> &num, int target, int from, set<vector<int> >&result)
{
	if (target < 0)
		return;
	if (target == 0) {
		vector<int> tmp = picked;
		result.insert(tmp);
		return;
	}
	if (num.size() == from)
		return;
	picked.push_back(num[from]);
	solve(picked, num, target - num[from], from + 1, result);

	picked.pop_back();
	solve(picked, num, target, from + 1, result);
}


class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
		sort(num.begin(), num.end());
		set<vector<int> > result;
		vector<int> picked;
		solve(picked, num, target, 0, result);
		return vector<vector<int> > (result.begin(), result.end());
    }
};


int main(int argc, char *argv[])
{
	Solution s;
	int c[] =  {10,1,2,7,6,1,5};

	vector<int> vc(c, c + sizeof(c)/sizeof(int));

	vector<vector<int> > result = s.combinationSum2(vc, 8);
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) {
			printf("%d ", result[i][j]);
		}
		printf("\n");
	}
    return 0;
}
