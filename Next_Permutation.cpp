/*
Next Permutation
Implement next permutation, which rearranges numbers into
the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it
as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column
and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

1. Find the largest index k such that a[k] < a[k + 1].
   If no such index exists, the permutation is the last permutation.
2. Find the largest index l such that a[k] < a[l]. Since k + 1 is such an
   index, l is well defined and satisfies k < l.
3. Swap a[k] with a[l].
4. Reverse the sequence from a[k + 1] up to and including the final element a[n].

*/

class Solution {
public:
    void nextPermutation(vector<int> &num) {
    	int n = num.size();
		int i;
		for (i = n - 2; i >= 0; i--) {
			if (num[i] < num[i+1])
				break;
		}
		if (i == -1) {
			//5 4 3 2 1
			reverse(num.begin(), num.end());
			return;
		}
		int j;
		for (j = n - 1; j >= i; j--) {
			if (num[i] < num[j]) {
				break;
			}
		}
		//swap i, j
		int tmp = num[i];
		num[i] = num[j];
		num[j] = tmp;
		reverse(num.begin() + i + 1, num.end());
    }
};
