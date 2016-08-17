class Solution {
public:
    // DP
    // f(n) = max(f(n-1), f(n-2) + nums[n]);
    
    int linearRob(vector<int> & nums, int start, int end){
        int prepre = 0, pre = nums[start], val = 0;
        for (int i = start+1; i < end; ++i) {
            val = max(prepre + nums[i], pre);
            prepre = pre, pre = val;
        }
        return val;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        return max(linearRob(nums,0, n-1), linearRob(nums,1,n));
    }
};