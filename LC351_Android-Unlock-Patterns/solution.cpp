    // check if the ith number is visited or not
    bool isVisited(int i, int table) {
        return table & (1 << i);
    }
    
    bool isValidMove(int cur, int pre, int table) {
        if (isVisited(cur, table)) return false;
        
        // no number has been used or no gap, then is a valid move
        int rowSum = cur/3 + pre/3;
        int colSum = cur%3 + pre%3;
        if (table == 0 || rowSum % 2 || colSum % 2) return true;
        
        // if there is a gap
        int mid = rowSum/2*3 + colSum/2;
        return isVisited(mid, table);
    }
    
    int patternNum(int m, int n, int curLen, int visitedTable, int pre, vector<int> &cache) {
        if (curLen == n) return 1;
        
        // search cached state
        int stateCode = visitedTable + (pre << 9);
        if (cache[stateCode] > 0) return cache[stateCode];
        
        int count = (m <= curLen) ? 1 : 0;
        for (int i = 0; i < 9; ++i) {
            if (isValidMove(i, pre, visitedTable)) {
                count += patternNum(m, n, curLen + 1, visitedTable | (1 << i), i, cache);
            }
        }
        cache[stateCode] = count;
        return count;
    }

    int numberOfPatterns(int m, int n) {
        vector<int> cache(4608,-1);
        return patternNum(m, n, 0, 0, 4, cache);
    }
