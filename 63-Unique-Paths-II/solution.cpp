class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
       
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        if (obstacleGrid[0][0]) return 0;
        
        vector<int> dp(m+1,0);
        dp[1] = 1;
        for (int i = 0; i < n; ++i) 
            for (int j = 0; j < m; ++j) {
                dp[j+1] = obstacleGrid[i][j] ? 0 : dp[j+1] + dp[j];
            }
        return dp[m];
    }
};