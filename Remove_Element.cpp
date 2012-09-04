/*
  Remove Element
Given an array and a value, remove all instances of
that value in place and return the new length.

The order of elements can be changed. It doesn't
matter what you leave beyond the new length.

 */
class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int j = n - 1;
        while (j >= 0 && A[j] == elem)
            j--;

        for (int i = 0; i <= j && i < n; i++) {
            if (A[i] == elem) {
                int tmp = A[j];
                A[j] = A[i];
                A[i] = tmp;

                while (j >= 0 && A[j] == elem)
                    j--;
            }
        }
        return j+1;
    }
};
