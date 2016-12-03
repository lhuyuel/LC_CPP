class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int left = matrix[0][0], right = matrix[n-1][n-1];
        while (left < right) {
            int midValue = (right-left)/2 + left;
            int count = 0;
            for (auto row : matrix) {
                count += (upper_bound(row.begin(), row.end(), midValue) - row.begin());
            }
            if (count < k) left = midValue + 1;
            else right = midValue;
        }
        return left;
    }
};