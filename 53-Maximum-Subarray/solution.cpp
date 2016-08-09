class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (sum >= 0) sum += nums[i];
            else sum = nums[i];
            maxSum = max(sum, maxSum);
        }
        return maxSum;
    }
};