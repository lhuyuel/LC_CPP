class Solution {
public:
    // 求转折点的个数
    int wiggleMaxLength(vector<int>& nums) {
        int count = nums.size() > 0 ? 1 : 0;
        int diff_pre = 0;
        for (int i = 1; i < nums.size(); ++i) {
            int diff = nums[i] - nums[i-1];
            if (diff_pre == 0 && diff != 0 || diff * diff_pre < 0) {
                diff_pre = diff;
                ++count;
            }
        }
        return count;
    }
};