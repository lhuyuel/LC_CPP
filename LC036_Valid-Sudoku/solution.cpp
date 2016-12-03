class Solution {
public:

    bool isValidSudoku(vector<vector<char>>& board) {
        int i, j;
        int col[9] = {0}, row[9] = {0}, sq[9] = {0};
        for (i = 0; i < 9; ++i) {
            for (j = 0; j < 9; ++j) {
                if (board[i][j] == '.') continue;
                int num = board[i][j] - '1';
                int mask = 1 << num;
                int combined = (sq[(i/3)*3+(j/3)] | col[j] | row[i]);
                if (combined & mask) return false;
                sq[(i/3)*3 + (j/3)] |= mask; col[j] |= mask; row[i]|= mask;
            }
        }
        return true;
    }
};