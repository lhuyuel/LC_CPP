class Solution {
public:
    // DFS
    void dfs(vector<int>& nums, int target, int start, vector<int> &path, vector<vector<int>> &result) {
        if (target == 0) {
            result.push_back(path);
            return;
        }
        for (int i = start; i < nums.size(); ++i) {
            if (nums[i] > target) continue;
            path.push_back(nums[i]);
            dfs(nums, target-nums[i], i, path, result);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> path;
        sort(candidates.begin(),candidates.end());
        dfs(candidates,target, 0,path, result);
        return result;
    }
};