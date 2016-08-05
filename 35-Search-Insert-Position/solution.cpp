class Solution {
public:
    // 其实就是lowerbound的实现，可以使用binary search
    int searchInsert(vector<int>& nums, int target) {
        int start = 0, end = nums.size()-1;
        while (start <= end) {
            int mid =  (end-start)/2 + start;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target) {
                start = mid + 1;
            }
            else end = mid - 1;
        }
        if (start <= nums.size()) return start;
        else return end;
        
    }
};