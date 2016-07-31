class Solution {
public:

/*
coins = [1, 2, 5], amount = 11
*/
    int coinChange(vector<int>& coins, int amount) {
       //if (amount < coins[0]) return -1;    
       int n = coins.size();
       vector<int> f(amount+1, -1);
       f[0] = 0;
       for (int i = 0; i < n; ++i) 
            f[coins[i]] = 1;
       
       for (int j = 1; j <= amount; ++ j) {
            int minNum = INT_MAX;
            for (int i = 0; i < n; ++i) {
                 if ( j >= coins[i] && f[j-coins[i]] != -1) { 
                    if (f[j-coins[i]] + 1 < minNum)
                        minNum =  f[j-coins[i]] + 1;
                 }
            }
            if (minNum != INT_MAX)
                f[j] = minNum;
       }
       return f[amount];
    }
};