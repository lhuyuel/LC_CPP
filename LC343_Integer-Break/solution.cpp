class Solution {
public:
    /*
    2 => 1, 1 => 1
    3 => 2, 1 => 2
    4 => 2, 2 => 4
    5 => 3, 2 => 6
    6 => 3, 3 => 9
    7 => 3, 4 => 12
    8 => 3, 5 => 18
    9 => 3, 6 => 27
    10 => 3, 7 => 36

    By observation, when you get maximum, one of the num is always 3.
    After 3, the result will be larger than or equal the number itself.
    */
    int integerBreak(int n) {
        vector<int> dp(n+1,0);
        dp[2] = 1;
        dp[3] = 2;
        dp[4] = 4;
        for (int i = 5; i <= n; ++i) {
            dp[i] = max(dp[i-3], i-3) * 3;
        }
        return dp[n];
    }
};