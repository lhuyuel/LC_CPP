    /*
        f(i,j) =  max(min (f(i+1,j),f(i,j+1)) - grid[i][j], 1)
        如果当前格子是正数，意味着经过当前格可以获得体力，但在到达这个格子前必须至少有1点体力。
    */
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(); // rows 1
        int n = dungeon[0].size(); // cols 1
        vector<int> dp(n+1, INT_MAX);
        dp[n] = INT_MAX; //这里设为INT_MAX是为了表示最右侧和下方的墙
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
		// 如果当前在右下角的grid，则dp[j]就是1- dungeon[i][j]。
                dp[j] = (i == m-1 && j == n-1) ? max(1 - dungeon[i][j], 1): max( min(dp[j], dp[j+1]) - dungeon[i][j], 1);
            }
        }
        return dp[0];
    }
