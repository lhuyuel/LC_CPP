class Solution {
public:

    // f[n] = max(f[n-1] ,f[n-2] + nums[n] )
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        // table[i]表示 抢完第i个房子的赃款数
        vector<int> table(n+1, 0);
        table[0] = nums[0];
        table[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; ++i) {
            table[i] = max(table[i-1], table[i-2] + nums[i]);
        }
        return table[n-1];
    }
};