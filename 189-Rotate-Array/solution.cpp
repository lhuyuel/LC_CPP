class Solution {
public:
    void reverse(vector<int> &nums, int start, int end) {
        for (int i = start, j = end; i < j; ++i, --j) {
            int tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        reverse(nums, 0 , n-1);
        reverse(nums, 0, k-1);
        reverse(nums, k, n-1);
    }
};