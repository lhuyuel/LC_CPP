class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result;
        result.push_back(0);
        if (num == 0) return result;
        
        result.push_back(1);
        if (num == 1) return result;
        
        int count = 2;
        while (count <= num) {
            int len = result.size();
            for (int i = 0; i < len && count <= num; ++i) {
                result.push_back(result[i] + 1);
                ++count;
            }
        }
        return result;
    }
};