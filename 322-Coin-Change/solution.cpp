class Solution {
public:

/*
coins = [1, 2, 5], amount = 11
*/
    int coinChange(vector<int>& coins, int amount) {
       int n = coins.size();
       vector<int> f(amount+1, 0);
       for (int i = 0; i < n; ++i) 
            f[coins[i]] = 1;
       
       for (int j = 1; j <= amount; ++ j) {
            int minNum = INT_MAX;
            for (int i = 0; i < n; ++i) {
                 if ( j >= coins[i] && f[j-coins[i]] + 1 < minNum)
                     minNum =  f[j-coins[i]] + 1;
            }
            f[j] = minNum;
       }
       return f[amount];
    }
};