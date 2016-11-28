    // return the largest number we can get by picking k numbers from array nums
    vector<int> findMax(const vector<int> &nums, int k) {
        int n = nums.size();
        vector<int> result;
        if (k == 0 || k > n) return result;
        int curMax = nums[0], max_idx = 0;
        for (int i = 1; i <= k; ++i) {
            // find the larget number in index range [max_idx,n-i-1]
            for (int j = max_idx + 1; j < n - k + i; ++j) {
                if (nums[j] > curMax) {
                    curMax = nums[j];
                    max_idx = j;
                }
            }
            result.push_back(nums[max_idx]);
            curMax = INT_MIN;
        }
        return result;
    }
    
    bool greater(vector<int>& nums1, vector<int>& nums2, int i, int j) {
        for (; i < nums1.size(); ++i, ++j) {
            if (j >= nums2.size()) return true;
            if (nums1[i] > nums2[j]) return true;
            if (nums1[i] < nums2[j]) return false;
        }
        return false;
    }
    
    vector<int> mergeNums(vector<int> n1, vector<int> n2) {
            vector<int> result(n1.size() + n2.size(), 0);
            for (int i = 0, j = 0, k = 0; i < n1.size() || j < n2.size(); ++k)
                result[k] = greater(n1, n2, i, j)? n1[i++] : n2[j++];
            return result;
    }
    
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> result;
        for (int i = 0; i <= k && i <= nums1.size(); ++i) {
            if (i > nums1.size() || k-i > nums2.size()) continue; // 如果没有这一句过不了test case[1,2]，[]，2
            vector<int> tmp = mergeNums(findMax(nums1,i), findMax(nums2,k-i));
            if (tmp > result) result = tmp;
        }
        return result;
    }
