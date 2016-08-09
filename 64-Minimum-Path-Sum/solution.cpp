class Solution {
public:
    // DP: f(m,n) = min(f(m-1,n), f(m, n-1)) + grid[m-1][n-1];
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dpRow(n+1, 0);
        for (int i = 1; i <= n; ++i) dpRow[i] += dpRow[i-1]+ grid[0][i-1];
        dpRow[0] = INT_MAX;
        
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j <= n; ++j) {
                dpRow[j] = min(dpRow[j-1],dpRow[j]) + grid[i][j-1];
            }
        }
        return dpRow[n];
    }
};