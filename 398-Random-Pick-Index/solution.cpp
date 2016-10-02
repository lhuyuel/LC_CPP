class Solution {
public:
    Solution(vector<int> nums) {
        nums_ = nums;
    }
    
    int pick(int target) {
        int idx = -1, cnt = 0;
        for (int i = 0; i < nums_.size(); ++i) {
            if (nums_[i] == target) {
                ++cnt;
                if (cnt == 1) idx = i;
                if (rand()%cnt == 0) idx = i;
            }
        }
        return idx;
    }
private:
    vector<int> nums_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */