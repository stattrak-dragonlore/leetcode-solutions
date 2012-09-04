/*
  Permutation Sequence
The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.

 */
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


class Solution {
public:

    string getPermutation(int n, int k) {
		vector<char> v;
		for (int i = 1; i <= n; i++)
			v.push_back(i + '0');

        int factorial = 1;
        /*  (n-1)! */
        for (int i = 2; i <= n-1; i++)
            factorial *= i;

        string result;
		k = k - 1;
        for (int i = 0; i < n - 1; i++) {
            result += v[k/factorial];
			v.erase(v.begin() + k/factorial);
			sort(v.begin(), v.end());
			k %= factorial;
			factorial /= (n-i-1);
        }
		result += v[0];
        return result;
    }
};


int main(int argc, char *argv[])
{

	Solution s;

	cout << s.getPermutation(2, 1) << endl;
    cout << s.getPermutation(2, 2) << endl;
	cout << s.getPermutation(3, 4) << endl;
	cout << s.getPermutation(3, 3) << endl;
	cout << s.getPermutation(3, 2) << endl;
	cout << s.getPermutation(3, 1) << endl;
	cout << s.getPermutation(3, 6) << endl;
	return 0;
}
