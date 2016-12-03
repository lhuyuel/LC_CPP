    /*
        If a < b, b%a == 0 and b < c, b%c == 0 then c%a = 0
        f(i) is the longest subset ending at i
        if (nums[j] % nums[i] == 0 && f(i) < f(j) + 1) update f(i)
        
        since need to return actual subset, have to remember prevoius elem/index
    */
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size(), maxLen = 0, maxIdx = 0;
        vector<int> dp(n), pre(n);
        sort(nums.begin(), nums.end());
        
        for (int i = n - 1; i >= 0; --i)
            for (int j = i; j < n; ++j) {
                if (nums[j] % nums[i] == 0 && dp[i] < dp[j] + 1) {
                    /// update dp[i]
                    dp[i] = dp[j] + 1;
                    pre[i] = j;
               
                    // remember previous index
                    pre[i] = j;
                    // update maxLen and maxIdx so we can backtrack
                    if (dp[i] > maxLen) {
                        maxLen = dp[i];
                        maxIdx = i;
                    }
                }
            }
            
        vector<int> result;
        for (int i = 0; i < maxLen; ++i) {
            result.push_back(nums[maxIdx]);
            maxIdx = pre[maxIdx];
        }
        return result;
    }
