class Solution {
public:
    // Binary search
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size()-1, mid = 0;
        while (left < right) {
            if (left == (right-1)) return min(nums[left],nums[right]);
            mid = (right - left)/2 + left;
            if (nums[left] > nums[mid]) right = mid;
            if (nums[mid] > nums[right]) left = mid;
        }
        return nums[left];
    }
};