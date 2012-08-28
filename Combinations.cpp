/*
Combinations
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

*/

#include <algorithm>
#include <vector>
#include <set>

using namespace std;


void comb(vector<int> &picked, int from, int k, int n, vector<vector<int> > &result)
{
	if (k == 0) {
		vector<int> tmp = picked;
		result.push_back(tmp);
		return;
	}
	if (from > n)
		return;

	picked.push_back(from);
	comb(picked, from+1, k-1, n, result);

	picked.pop_back();
	comb(picked, from+1, k, n, result);
}

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
		vector<int> picked;
		vector<vector<int> > result;
		comb(picked, 1, k, n, result);
		return result;
    }
};


int main(int argc, char *argv[])
{
	Solution s;
	vector<vector<int> > result = s.combine(4, 2);
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) {
			printf("%d ", result[i][j]);
		}
		printf("\n");
	}
	return 0;

}
