class Solution {
public:
    void sortColors(vector<int>& nums) {
        int redTail = 0, blueHead = nums.size()-1;
        int i = 0;
        while (i <= blueHead) {
            if (nums[i] == 0) swap(nums[i], nums[redTail++]);
            if (nums[i] == 2) swap(nums[i], nums[blueHead--]);
            else ++i;
        }
    }
};