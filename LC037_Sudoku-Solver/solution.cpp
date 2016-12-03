class Solution {
public:
    /* dsf 
       try each options for each position, the brute force dfs will take exponential time
       give a heurist will devrease the time dramatically.
       for positions that are empty, we choose the one that has fewest options
       
       could divide the whole process into several parts: 
       - vector<int> getOptions(int x, int y): check if current
       - pair<x,y> getNextEmpty(vector<vector<char>>& board):  get next empty cell that has least options
       - void dfs(vector<vector<char>>& board, int startX, int startY)
    */
    vector<int> getOptions(pair<int,int> pos, vector<vector<char>>& board) {
        vector<int> opts;
        vector<bool> checkDup(9, false);
        // check row
        for (int i = 0; i < 9; ++i) {
            if (board[pos.first][i] != '.') {
                int num = board[pos.first][i] - '0';
                checkDup[num-1] = true;
            }
        }
        
        //check col
        for (int i = 0; i < 9; ++i) {
            if (board[i][pos.second] != '.') {
                int num = board[i][pos.second] - '0';
                checkDup[num-1] = true;
            }
        }
        
        // check square     row index should be pos.first/3
        int row = pos.first/3, col = pos.second/3;
        for (int i = row; i < row + 3; ++i)
            for (int j = col; j < col + 3; ++j) 
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0';
                    checkDup[num-1] = true;
                }
        
        // check checkDup array, if false push to result
        for ( int i = 0; i < checkDup.size(); ++i)
            if (!checkDup[i]) opts.push_back(i+1);
        
        return opts;
    }
    
    // return {INT_MIN,INT_MIN} if no empty cell left
    // table stores {pos, options} pair
    pair<int,int> getNextEmpty(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        int minOp = INT_MAX, minX = INT_MIN, minY = INT_MIN;
        for (int i = 0; i < m; ++i) 
            for (int j = 0; j < n; ++j)
                // if it is empty check its options
                if (board[i][j] == '.') {
                    vector<int> opts = getOptions({i,j}, board);
                    //table[i][j] = opts;
                    if (opts.size() < minOp) {
                        minX = i, minY = j;
                        minOp = opts.size();
                    }
                }
            
        return {minX, minY};
    }
    //vector<vector<char>> sol;
    // unordered_map<pair<int,int>, vector<int>> &table
    bool dfs(vector<vector<char>>& board) {
        //vector<vector<vector<int>>> table(9,vector<vector<int>>(9));
        pair<int,int> curPos = getNextEmpty(board);
        
        // termination condition
        if (curPos.first == INT_MIN && curPos.second == INT_MIN) {
            return true;
        }
        
        //vector<int> opts = table[curPos.first][curPos.second];
        vector<int> opts = getOptions(curPos,board);
        for (int i = 0; i < opts.size(); ++i) {
            board[curPos.first][curPos.second] = opts[i] + '0';
            if ( dfs(board)) return true;
            board[curPos.first][curPos.second] = '.';
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        //vector<vector<vector<int>> table;
        dfs(board);
    }
};
