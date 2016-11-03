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

// 20161103 题目修改了，solution不能有重复
    void combinationSumHelper(vector<int>& candidates, int target, vector<int> &sol,vector<vector<int>> &result) {
        // termination condition
        if (target == 0) {
            result.push_back(sol);
            return;
        }
        
        // try every options
        for (auto c: candidates) {
            // prune
            if (target - c >= 0) {
                sol.push_back(c);
                combinationSumHelper(candidates, target - c, sol, result);
                sol.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> sol;
        vector<vector<int>> result;
        sort(candidates.begin(), candidates.end());
        combinationSumHelper(candidates,target, sol, result);
        if (result.size() != 0) {
            // remove dup
            for (auto &v : result) sort(v.begin(), v.end());
            sort(result.begin(), result.end());
            
            int count = 0;
            for (int i = 1; i < result.size(); ++i)
                if (result[i] != result[count]) result[++count] = result[i];
            result.resize(count+1);
        }
        return result;
    }
