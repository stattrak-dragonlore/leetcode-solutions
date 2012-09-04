/*
Search a 2D Matrix
Write an efficient algorithm that searches for a value
in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.


see http://en.wikipedia.org/wiki/Young_tableau

solved in O(n+m)

*/

bool search(vector<vector<int> > &m, int rs, int ce, int target)
{
    int r = m.size();
    if (r == rs)
        return false;

    int c = m[rs].size();
    if (c == ce)
        return false;

    int e = m[rs][c - 1 - ce];
    if (target == e)
        return true;
    else if (target < e) {
        return search(m, rs, ce + 1, target);
    } else {
        return search(m, rs + 1, ce, target);
    }
}

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        return search(matrix, 0, 0, target);
    }
};
