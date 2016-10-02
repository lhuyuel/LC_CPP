class Solution {
public:
    // beat 100% :)
    // keep an array of current increasing sub, size is 3
    bool increasingTriplet(vector<int>& nums) {
        int minNum1 = INT_MAX, minNum2 = INT_MAX;
        for (int i = 0; i < nums.size(); ++i) {
            // current number is less then the min from before
            if (nums[i] <= minNum1) minNum1 = nums[i];
            else {
                if (nums[i] <= minNum2) minNum2 = nums[i];
                // means nums[i] > the second smallest number, then it is the third smallest
                else return true;
            }
        }
        return false;
    }
};