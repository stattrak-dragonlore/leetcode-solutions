/*
   Set Matrix Zeroes
Given a m x n matrix, if an element is 0, set its entire row and column to 0.
Do it in place.

Follow up:
Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?

 */
class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int r = matrix.size();
        if (r == 0)
            return;
        int c = matrix[0].size();

        int zero_first_col = 0;
        int zero_first_row = 0;
        for (int i = 0; i < r; i++) {
            if (matrix[i][0] == 0)
                zero_first_col = 1;
        }
        for (int j = 0; j < c; j++)
            if (matrix[0][j] == 0)
                zero_first_row = 1;

        for (int i = 1; i < r; i++) {
            for (int j = 1; j < c; j++)
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
        }

        for (int i = 1; i < r; i++) {
            if (matrix[i][0] == 0) {
                for (int j = 1; j < c; j++)
                    matrix[i][j] = 0;
            }
        }

        for (int j = 1; j < c; j++) {
            if (matrix[0][j] == 0) {
                for (int i = 1; i < r; i++)
                    matrix[i][j] = 0;
            }
        }

        if (zero_first_col)
            for (int i = 0; i < r; i++)
                matrix[i][0] = 0;
        if (zero_first_row)
            for (int j = 0; j < c; j++)
                matrix[0][j] = 0;
    }
};
