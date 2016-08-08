class Solution {
public:
    // DFS
    
    void comSum(int start, int k, int n, vector<int> &path, vector<vector<int>> &result) {
        if (k == 0 && n == 0) {
            result.push_back(path);
            return;
        }
        
        for (int i = start; i <= 9; ++i) {
            if (start > n) return;
            path.push_back(i);
            comSum(i+1, k-1, n-i,path,result);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> path;
        comSum(1,k,n,path,result);
        return result;
    }
};