class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> level;
        
        level.push_back(1);
        if (rowIndex == 0) return level;
        
        level.push_back(1);
        if (rowIndex == 1) return level;
        
        for(int i = 1; i < rowIndex ;++i) {
            level.insert(level.begin(), 1);
            for (int j = 1; j < level.size()-1; ++j) {
                level[j] += level[j+1];
            }
        }
        return level;
    }
};