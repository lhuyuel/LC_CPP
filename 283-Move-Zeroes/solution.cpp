class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count = 0;
        for (auto num : nums)
            if (num) nums[count++] = num;
        for (int i = count; i < nums.size(); ++i) 
            nums[i] = 0;
    }
};