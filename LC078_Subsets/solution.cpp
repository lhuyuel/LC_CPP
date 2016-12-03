class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subs;
        int n = nums.size();
        int sub_nums = 1 << n;
        //result.push_back(subs);
        for (int i = 0; i < sub_nums; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i & (1<<j)) subs.push_back(nums[j]);
            }
            result.push_back(subs);
            subs.clear();
        }
        return result;
    }
};