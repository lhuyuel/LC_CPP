class Solution {
public:
    void dfs(vector<int>& nums, int start, vector<int> path, vector<vector<int>> &result) {
        int n = nums.size();
        if (start == n-1) {
            path.push_back(nums[n-1]);
            result.push_back(path);
        }
        
        for (int i = start; i < n; ++i) {
            path.push_back(nums[i]);
            swap(nums[start], nums[i]);
            dfs(nums, start+1, path, result);
            path.pop_back();
            swap(nums[start],nums[i]);
        }
    }


    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> path;
        dfs(nums, 0, path, result);
        return result;
    }
};