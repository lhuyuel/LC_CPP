class Solution {
public:

/*
coins = [1, 2, 5], amount = 11
*/
    int coinChange(vector<int>& coins, int amount) {
        vector<int> f(amount+1, INT_MAX);
        f[0] = 0;
       
       
        for (int j = 0; j < coins.size(); ++j)
            for (int i = coins[j]; i <= amount; ++i) {
                f[i] = min(f[i-coins[j]] + 1, f[i]);
            }    
        return f[amount] == INT_MAX ? -1 f[amount];
    }
};