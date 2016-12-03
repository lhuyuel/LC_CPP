class Solution {
public:
    // 就是change Coins吧
    // dp(n) = dp(n-nums[0]) + dp(n-nums[1]) +...
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(target+1,0);
        for (int i = 0; i < n; ++i ) 
            if (nums[i] <= target) dp[nums[i]] = 1;
        for (int i = 0; i <= target; ++i) {
            for (auto num : nums) {
                if (i > num) dp[i] += dp[i-num];
            }
        }
        return dp[target];
    }
};