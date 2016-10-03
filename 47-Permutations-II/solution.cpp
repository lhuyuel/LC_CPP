class Solution {
public:
    // same number with diff index considered the same 
    // if permute and then reduce dup will cost much more computation if there are a lot of dups 
    
    /* Test Case:
 premute[0,0,0,1,9] = 0 + premute[0,0,1,9]
                              0 + permute[0,1,9]
                                     0 + premute[1,9]
                                             1+ permute[9]
                              9 + permute[0,0,1]
                                      0 + permute[0,1]
                                      1 + premute[0,0]
                      1 + premute[0,0,0,9]

Your answer

[[0,0,1,9],[0,0,9,1],[0,1,0,9],[0,1,9,0],[0,9,1,0],[0,9,0,1],[1,0,0,9],[1,0,9,0],[1,9,0,0],[9,0,1,0],[9,0,0,1],[9,1,0,0],
[9,0,1,0],[9,0,0,1]]
Expected answer

[[0,0,1,9],[0,0,9,1],[0,1,0,9],[0,1,9,0],[0,9,0,1],[0,9,1,0],[1,0,0,9],[1,0,9,0],[1,9,0,0],[9,0,0,1],[9,0,1,0],[9,1,0,0]]
    
    
    
    */
    
    
    void permute(vector<int> &nums, int start,vector<int> path, vector<vector<int>> &result) {
        int n = nums.size();
        
        // termination condition
        if (start == n-1) {
            path.push_back(nums[start]);
            result.push_back(path);
        }
        
        // dfs
        int pre = INT_MAX;
        for (int i = start; i < n; ++i) {
            // need to compare to the previous number
            if (pre != nums[i]) {
                path.push_back(nums[i]);
                swap(nums[start], nums[i]);
                permute(nums,start+1,path,result);
                swap(nums[start], nums[i]);
                path.pop_back();
            }
            pre = nums[i];
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        // after the sort, same number will be adjacent to each other
        vector<vector<int>> result;
        vector<int> path;
        permute(nums, 0, path, result);
        set<vector<int>> tmp(result.begin(),result.end());
        result.resize(tmp.size());
        copy(tmp.begin(),tmp.end(),result.begin());
        return result;
    }
};