class Solution {
public:
    vector<int> oriNums;
    
    Solution(vector<int> nums) {
        for (auto num :nums)
            oriNums.push_back(num);
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return oriNums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> shuffled = oriNums;
        for (int i = 0; i < shuffled.size(); ++i) {
            default_random_engine gen((random_device())()); // Random num generator
            // get random number r between [i, shuffled.size()-1], and then swap(shuffled[i], shuffled[r]);
            uniform_int_distribution<int> dis(i,shuffled.size()-1);
            swap(shuffled[i], shuffled[dis(gen)]);
        }
        return shuffled;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */