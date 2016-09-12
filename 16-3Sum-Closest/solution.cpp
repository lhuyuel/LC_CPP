class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int minSum = INT_MAX;
        int minDiff = INT_MAX;
        for (int i = 0; i < nums.size()-2; ++i) {
            int l = i+1, r = nums.size() - 1;
            while (l < r) {
                int tmpSum = nums[i] + nums[l] + nums[r];
                if ( tmpSum == target)
                    return target;
                else if (tmpSum < target)
                    ++l;
                else 
                    --r;
                
                if (abs(tmpSum - target) < minDiff ) {
                        minSum = tmpSum;
                        minDiff = abs(tmpSum - target);
                }
            }
        }
        return minSum;
    }
};