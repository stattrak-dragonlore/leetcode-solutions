/*
  Permutations
Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].

 */

int next_perm(vector<int> &num, vector<vector<int> >&result)
{
    int n = num.size();
    int i;
    for (i = n-2; i >= 0; i--) {
        if (num[i+1] > num[i])
            break;
    }
    if (i == -1)
        return 0;

    int j;
    for (j = n-1; j >= 0; j--) {
        if (num[j] > num[i])
            break;
    }
    swap(num[j], num[i]);
    reverse(num.begin() + i + 1, num.end());
    result.push_back(num);
    return 1;
}

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num)
    {
        sort(num.begin(), num.end()); //important
        vector<vector<int> > result;
        if (num.size() > 0) {
            result.push_back(num);
            while (next_perm(num, result))
                ; //
        }
        return result;
    }
};
