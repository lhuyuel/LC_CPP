class Solution {
public:
    // 求sum(1,n),以及数组所有元素和，然后求差
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (auto num : nums) sum += num;
        return (n+1)*n/2 - sum;
    }
};