class Solution {
public:

/*
coins = [1, 2, 5], amount = 11
*/
    int coinChange(vector<int>& coins, int amount) {
        //int Max = amount + 1;
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            int minNum = INT_MAX;
            for (int j = 0; j < coins.size(); ++j) {
                if (dp[i - coins[j]] != INT_MAX && coins[j] <= i) {
                    minNum = min(minNum, dp[i - coins[j]] + 1);
                }
            }
            dp[i] = minNum;
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};