class Solution {
public:
    //前面直接遍历是 O(n)的复杂度，如果要O(logn)那只能binary search了吧
    int hIndex(vector<int>& citations) {
        // if citations[mid] >= mid , search left
        // if citationsp[mid] < mid, search right
        int n = citations.size();
        int left = 0, right = n -1, mid = 0;
        while (left <= right) {
            mid = (right - left) / 2 + left;
            if (citations[mid] >= n - mid) right = mid - 1;
            else left = mid + 1;
        }
        return n - left;
    }
};