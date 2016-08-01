class Solution {
public:
    // 方法1：sort the array, and then check. Complexity: O(nlogn)
    // 方法2：hashTable
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i-1] == nums[i])
                return true;
        }
        return false;
    }
};