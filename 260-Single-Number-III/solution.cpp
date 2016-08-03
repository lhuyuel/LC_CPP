class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> result(2,0);
        // 求出a^b
        int x = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            x ^= nums[i];
        }
        
        // 求出x最后一位1 作为mask
        x &= -x;
        
        // 将原数组各个数与mask&，分为两组，a、b必定分别在两组中，分别^即可
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] & x)
                result[0] ^= nums[i];
            else 
                result[1] ^= nums[i];
        }
        return result;
    }
};