class Solution {
public:
    void dfs(vector<int>& nums, int target, int start, vector<int> &solution, vector<vector<int>> &result){
        if( target == 0 ){
            result.push_back(solution);
            return;
        }
        int pre = -1;
        for(int i = start; i< nums.size(); ++i){
            if( nums[i] > target ) return;
            if (nums[i] == pre) continue; // 这一句保证了没有重复的组合
            solution.push_back(nums[i]);
            dfs(nums, target-nums[i], i+1, solution, result ); // i+1 保证了同一个index的数不会用第二次
            solution.pop_back();
            pre = nums[i];
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> solution;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, solution, result);
        return result;
    }
};