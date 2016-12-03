class Solution {
public:
    // dp[i][j] = min(dp[i-1][j],dp[i-1][j+1]) + triangle[i][j]
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp = triangle[triangle.size()-1];
        
        for (int i = n-2; i >= 0; --i) {
            for (int j = 0; j < triangle[i].size(); ++j){
                dp[j] = min(dp[j], dp[j+1]) + triangle[i][j];
            }
        }
        return dp[0];
    }
};