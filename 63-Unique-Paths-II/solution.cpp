class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
       
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        if (obstacleGrid[0][0]) return 0;
        
        vector<int> dp(m+1,0);
        dp[1] = 1;
        for (int i = 0; i < n; ++i) 
            for (int j = 1; j < m; ++j) {
                dp[j] = obstacleGrid[i-1][j-1] ? 0 : dp[j] + dp[j-1];
            }
        return dp[m];
    }
};