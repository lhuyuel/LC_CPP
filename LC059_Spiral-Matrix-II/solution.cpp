class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n,0));
        int num = 1, nsquare = n*n;
        int begin = 0, end = n-1;
        while (begin < end) {
            for (int i = begin; i < end; ++i) matrix[begin][i] = num++;
            for (int j = begin; j < end; ++j) matrix[j][end] = num++;
            for (int i = end; i > begin; --i ) matrix[end][i] = num++;
            for (int j = end; j > begin; --j ) matrix[j][begin] = num++;
            ++begin, --end;
        }
        if (begin == end) matrix[begin][end] = num;
        return matrix;
    }
};