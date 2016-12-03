class Solution {
public:
    // merge num2 to num1
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = m+n-1; i >= 0; --i) {
            if (n <= 0) break;
            if (m <= 0)
                nums1[i] = nums2[--n];
            else
                nums1[i] = (nums1[m-1] > nums2[n-1]) ? nums1[--m] : nums2[--n];
        }
    }
};