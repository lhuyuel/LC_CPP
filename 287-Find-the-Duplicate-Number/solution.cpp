class Solution {
public:
    // n+1 nums in total, in range [1,n], one duplicated
    // 好像和sum有关
    
    // 用sort的话，复杂度O(nlogn)不算太差，但好像还有更好的算法
    //  assign num to it's correspond index, if a num is already in the pos, then we find the dup.
    int findDuplicate(vector<int>& nums) {
        for(int i = 0; i < nums.size(); ++i) {
            while(nums[i] != i+1) {
                // nums[nums[i]] position has been occupied
                if (nums[nums[i]-1] == nums[i]) 
                    return nums[i];
                else 
                    swap(nums[i], nums[nums[i]-1]);
            }
        }
        return nums[nums.size()-1];
    }
};


// test case:  3 1 1 2   nums.size() = 4
// i = 0, nums[i] is 3 which is not = 1, enter the loop, check nums[2], nums[2] is 1 !=3, so swap(nums[0], nums[2])
// now array is: 1 1 3 2, still in the loop, nums[0] == 1 now, so exit loop, i = 1
// nums[1] = 1, != 2, so enter the loop,  nums[1-1] = nums[0] is 1, which is == nums[1], so return 1 