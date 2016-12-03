class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int tmp = 1, n = nums.size();
        vector<int> result(n,0);
        // get product of 0 to i-1
        int pre_product = 1;
        for (int i = 1; i < n; ++i) {
            pre_product *= nums[i-1];
            result[i] = pre_product;
        }
        
        // get product of i+1 to n
        pre_product = 1;
        result[0] = 1;
        for (int i = n-2; i >= 0; --i) {
            pre_product *= nums[i+1];
            result[i] *= pre_product;
        }
        return result;
    }
};