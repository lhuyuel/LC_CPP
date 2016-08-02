class Solution {
public:
    // 用一个table记录上一次这个int出现的index，作差，如果 <=k 则返回true
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> table;
        for (int i = 0; i < nums.size(); ++i) {
            if (table.find(nums[i]) != table.end()) {
                if ((i-table[nums[i]]) <= k) return true;
            }
            table[nums[i]] = i;
        }
        return false;
    }
};