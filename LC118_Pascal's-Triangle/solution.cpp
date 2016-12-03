class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        if (numRows < 1) return result;
        result.push_back(vector<int>(1,1));  //[1]
        if (numRows == 1) return result;
        result.push_back(vector<int>(2,1));  //[1,1]
        if (numRows == 2) return result;
        
        vector<int> level;
        for (int i = 2; i < numRows; ++i) {
            level = result[i-1];
            level.insert(level.begin(),1);
            for (int j = 1; j < level.size()-1; ++j) {
                level[j] += level[j+1];
            }
            result.push_back(level);
            level.clear();
        }
        
        return result;
    }
};