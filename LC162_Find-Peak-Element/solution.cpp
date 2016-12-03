class Solution {
public:

    // Binary Search O(logN)
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1, mid = 0;
        while (left+1 < right) {
            mid = (right-left)/2 + left;
            if (mid && nums[mid] < nums[mid-1]) right = mid -1;
            else left = mid;
        }
        return nums[left] > nums[right] ? left : right;
    }
};