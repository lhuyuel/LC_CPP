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
            dfs(nums, target-nums[i], i, path, result); //这里起始位置是i，因为可以选择当前元素，而对于i之后的元素则不能选择[0,i]的元素这样防止重复
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

