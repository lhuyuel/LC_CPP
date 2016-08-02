class Solution {
public:
    // 由于需要返回index就不能排序了。可以用hashTable
    // 另外需要问清楚，比如target是4，返回[0,0]吗？
    vector<int> twoSum(vector<int>& nums, int target) {
        // value-index pair
        unordered_map<int,int> table;
        vector<int> result;
        for (int i = 0; i < nums.size(); ++i) {
            if (table.find(target -nums[i]) != table.end()) {
                result.push_back(i);
                result.push_back(table[target -nums[i]]);
                break;
            }
            else table[nums[i]] = i;
        }
        return result;
    }
};