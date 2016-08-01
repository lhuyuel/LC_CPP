class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid[0][0]) return 0;
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        
        vector<int> dp(m+1,0);
    
        for (int i = 1; i < n; ++i) 
            for (int j = 1; j < m; ++j) {
                dp[j] = obstacleGrid[i-1][j-1]) ? 0 : dp[j] + dp[j-1];
            }
        return dp[m];
    }
};