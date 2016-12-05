/*
Solution 1: DP
设 f(i) 表示 以i结尾的LIS的长度。对于所有 j < i ，如果 num[i] > nums[j] 则 f(i) = max{ f(j) } + 1；如果 nums[i] 比前面的所有 nums[ j ] 都小 ，则 f(i) = 1。对于每一个 i 我们找到了以 nums[i] 结尾的LIS，那么最大的LIS就是在所有这些LIS里面取极大值。时间复杂度 O(n^2)，空间复杂度 O(n)。

Solution 2: Binary Search O(nlogn)
记住一个递增子序列，使用lowerBound查找插入点。
*/
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        vector<int> dp(n,1);
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        int maxLen = dp[0];
        for (int i = 1; i < n; ++i) {
            if (dp[i] > maxLen) maxLen = dp[i];
        }
        return maxLen;
    }
