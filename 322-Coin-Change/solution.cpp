class Solution {
public:

/*
coins = [1, 2, 5], amount = 11
*/
    int coinChange(vector<int>& coins, int amount) {
       if (amount == 0) return 0;
       sort(coins.begin(),coins.end());
       
       //if (amount < coins[0]) return -1;    
       int n = coins.size();
       vector<int> f(amount+1, -1);
       f[0] = 0;
       for (int i = 0; i < n; ++i) 
            f[coins[i]] = 1;
       
       for (int i = 1; i <= amount; ++ i) {
            int minNum = INT_MAX;
            for (int j = 0; j < n; ++j) {
                 if ( i >= coins[j] && f[i-coins[j]] != -1) { 
                    if (f[i-coins[j]] + 1 < minNum)
                        minNum =  f[i-coins[j]] + 1;
                 }
            }
            if (minNum != INT_MAX)
                f[i] = minNum;
       }
       return f[amount];
    }
};