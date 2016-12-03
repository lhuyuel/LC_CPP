class Solution {
public:
    // 1, [3,1,5,8] , 1
    // dp[i,j] = max( nums[k-1]*nums[k]*nums[k+1] + dp[i,k-1] + dp[k+1,j], 
    //                 nums[k] dp[i,j])    not blow up kth
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for (int len = 2; len < n; ++len) {
            for (int i = 0; i < n-len; ++i) {
                int j = i + len;
                for ( int k = i+1; k < j; ++k) {
                    dp[i][j] = max(nums[i]*nums[k]*nums[j] + dp[i][k] + dp[k][j], dp[i][j]);
                }
            }
        }
        return dp[0][n-1];
    }
};