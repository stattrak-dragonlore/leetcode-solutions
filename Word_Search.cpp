/*
  Word Search
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell,
where "adjacent" cells are those horizontally or vertically neighboring.
The same letter cell may not be used more than once.

For example,
Given board =

[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.

Solution: Brute force is ok.

*/

bool search(vector<vector<char> > &board, string word, int cr, int cc)
{
    if (word.size() == 0)
        return true;

    int offset[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    for (int i = 0; i < 4; i++) {
        int nr = cr + offset[i][0];
        int nc = cc + offset[i][1];
        if (nr >= 0 && nr < board.size() &&
            nc >= 0 && nc < board[0].size() &&
            board[nr][nc] == word[0])
        {
            board[nr][nc] = '.';
            if (search(board, word.substr(1), nr, nc)) {
                return true;
            }
            board[nr][nc] = word[0];
        }
    }
    return false;
}


class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        int r = board.size();
        if (r == 0)
            return false;
        int c = board[0].size();
        if (c == 0)
            return false;

        int w = word.size();
        if (w == 0)
            return true;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (board[i][j] != word[0]) {
                    continue;
                }
                char c = board[i][j];
                board[i][j] = '.';
                if (search(board, word.substr(1), i, j))
                    return true;
                board[i][j] = c;
            }
        }

        return false;
    }
};
