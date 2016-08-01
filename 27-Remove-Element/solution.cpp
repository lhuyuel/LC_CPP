class Solution {
public:
    // 这题和remove 0那题是一样的解法，用count来数不是val的数
    int removeElement(vector<int>& nums, int val) {
        int count = 0;
        for (auto num : nums)
            if (num != val) nums[count++] = num;

        return count;
    }
};