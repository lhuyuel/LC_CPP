class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> table = {0, 1, 1, 2};
        vector<int> result(num+1,0);
        int i = 0, count = 0;
        while (i <= num) {
            for (int j = 0; j < table.size(); ++j) {
                result[i++] = table[j] + count;
            }
            ++count;
        }
        return result;
    }
};