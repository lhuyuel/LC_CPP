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
        
        // check square
        
        
        return opts;
    }
    
    // return {INT_MIN,INT_MIN} if no empty cell left
    // table stores {pos, options} pair
    pair<int,int> getNextEmpty(vector<vector<char>>& board, unordered_map<pair<int,int>, vector<int>> &table) {
        int m = board.size(), n = board[0].size();
        int minOp = INT_MAX, minX = INT_MIN, minY = INT_MIN;
        for (int i = 0; i < m; ++i) 
            for (int j = 0; j < n; +j)
                // if it is empty check its options
                if (board[i][j] == '.') {
                    vector<int> opts = getOptions({i,j}, board);
                    table[{i,j}] = opts;
                    if (opts.size() < minOp) {
                        minX = i, minY = j;
                    }
                }
            
        return {minX, minY};
    }
    
    
    void dfs(vector<vector<char>>& board, unordered_map<pair<int,int>, vector<int>> &table) {
        table.clear();
        pair<int,int> curPos = getNextEmpty(board, table);
        
        // termination condition
        if (curPos.first == INT_MIN && curPos.second == INT_MIN) return;
        
        vector<int> opts = table[curPos];
        for (int i = 0; i < opts.size(); ++i) {
            board[curPos.first][curPos.second] = opts[i] + '0';
            dfs(board);
            board[curPos.first][curPos.second] = '.';
        }
    
    }

    void solveSudoku(vector<vector<char>>& board) {
        
    }
