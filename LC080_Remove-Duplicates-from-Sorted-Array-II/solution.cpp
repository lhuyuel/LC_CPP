class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if ( n <= 2) return n; 
        int count = 1; // count valid index
        int count2 = 1; // count dups
        for (int i = 1; i < n; ++i) {
            if (nums[i] == nums[i-1]) 
                ++count2;
            else count2 = 1;
            if (count2 <= 2) 
                nums[count++] = nums[i];
        }
        return count;
    }
};