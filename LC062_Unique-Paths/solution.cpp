class Solution {
public:
    // f(i,j) = f(i-1,j) + f(i, j-1);
    int uniquePaths(int m, int n) {
        vector<int> dp(m+1, 1);
        dp[0] = 0;
        for (int i = 1; i < n; ++i) 
            for (int j = 1; j <= m; ++j) {
                dp[j] += dp[j-1];
            }
        return dp[m];
    }
};