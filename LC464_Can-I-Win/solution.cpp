    /*  
        已经选过的number的state可以作为一个state存下来
    */
    bool canIWin(int maxNum, int target, string usedTable, unordered_map<string, bool> &cache) {
        // search in cache
        if (cache.find(usedTable) != cache.end()) 
            return cache[usedTable];
        string full(maxNum + 1, '1');
        full[0] = '0';
        if (usedTable == full && target > 0) 
            return cache[usedTable] = false;
        
        bool opCanWin;
        
        for (int i = maxNum; i >= 1; --i) {
            // If it has not been used, try to use i and see if palyer2 can win
            if (usedTable[i] == '0') {
                if (target - i <= 0) {
                    cache[usedTable] = true;
                    return cache[usedTable];
                }
                
                // check if player2 can win, when player1 chose i
                usedTable[i] = '1'; 
                opCanWin = canIWin(maxNum, target - i, usedTable, cache);
                usedTable[i] = '0';
                
                // 只要对手有一种会输我们就选那一种
                if (opCanWin == false ) { 
                    cache[usedTable] = true;
                    return true;
                }
            }
        }
        
        //if (opCanWin) cache[stateCode] = false;
        cache[usedTable] = false;
        return cache[usedTable]; // if player2 cannot win with any choice, player1 win
    }
    
    bool canIWin(int maxNum, int target) {
        if(maxNum * (maxNum + 1) < 2 * target)
            return false;
        string usedTable(maxNum+1, '0');
        unordered_map<string, bool> cache;
        return canIWin(maxNum, target, usedTable, cache);
    }
