class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<int> dp(m+1,1);
        
        for (int j = 1; j < m; ++j) 
                if (!obstacleGrid[0][m]) dp[j] = 0;

        for (int i = 1; i < n; ++i) 
            for (int j = 1; j < m; ++j) {
                if (!obstacleGrid[n][m]) dp[j] += dp[j-1];
                else dp[j] = 0;
            }
        return dp[m];
    }
};