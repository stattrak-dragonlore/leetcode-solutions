/*
 Rotate Image
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?

 */

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();

        //from outer to innner
        for (int i = 0; i < n/2; i++) {
            for (int j = 0; j < n - i * 2 - 1; j++) { //length of side
                int r = i, c = i + j;
                int nr, nc;
                int next = matrix[r][c];
                int save;
                for (int k = 0; k < 4; k++) {
					//move A[r][c] --> A[c][n-1-r]
                    nr = c;
                    nc = n - 1 - r;
                    save = matrix[nr][nc];
                    matrix[nr][nc] = next;
                    next = save;
                    r = nr;
                    c = nc;
                }
            }
        }

    }
};
