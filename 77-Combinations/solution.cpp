class Solution {
public:
    void combination(int n, int k, int start, vector<int> path, vector<vector<int>> &result) {
        if (k == 0) {
            result.push_back(path);
            return;
        }
        for (int i = start; i <= n; ++i) {
            path.push_back(i);
            combination(n, k-1, i+1, path, result);
            path.pop_back();
        }
    } 

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> path;
        combination(n, k, 1, path, result);
        return result;
    }
};