class Solution {
public:
    int getNeighborNum(vector<vector<int>>& board, int x, int y) {
        int n = board.size();
        int m = board[0].size();
        int count = 0;
        for (int i = x-1; i < x + 2 && i < n; ++ i) {
            if (i < 0) continue;
            for (int j = y-1; j < y+2 && j < m; ++j) {
                if (j < 0) continue;
                if (i == x && j == y) continue;
                if ( board[i][j] == 1 || board[i][j] == -1 ) ++count;
            }
        }
        return count;
    }

    void setCell(vector<vector<int>>& board) {
        for (int i = 0; i < board.size(); ++i)
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == -1) board[i][j] = 0;
                else if (board[i][j] == 2) board[i][j] = 1;
            }
        
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        
        for (int i = 0; i < board.size(); ++i)
            for (int j = 0; j < board[0].size(); ++ j) {
                int num = getNeighborNum(board, i, j);
                // if the cell is 0, check neighbors, if neighbor_num == 3, set to 2
                if (board[i][j] == 0 ) {
                    if (num == 3) board[i][j] = 2; // set it to live
                }
                else {
                    // if the cell is 1, check neighbors, if neighbor_num < 2|| neighbor_num > 3, set to -1
                    if (num < 2 || num > 3) board[i][j] = -1; // should already set to -1, why it is not set to 0?   
                }
            }
        
        setCell(board);
    }
};