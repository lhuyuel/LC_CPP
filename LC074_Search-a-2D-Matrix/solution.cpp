class Solution {
public:
    //  其实是把二维数组map到一维数组
    
    pair<int,int> getIdx(int i, int n) {
        return {i/n,i%n};
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = m*n-1, mid = 0;
        
        while (left <= right) {
            mid = (right-left)/2 + left;
            auto idxs = getIdx(mid, n);
            if (matrix[idxs.first][idxs.second] < target) left = mid + 1;
            else if (matrix[idxs.first][idxs.second] > target) right = mid - 1;
            else return true;
        }
        return false;
    }
};