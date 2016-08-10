class Solution {
public:
    // 先对角线交换，然后再左右交换
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; ++i)
            for (int j = i; j < n; ++j){
                swap(matrix[i][j],matrix[j][i]);
            }
        for (int i = 0; i < n; ++i) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};