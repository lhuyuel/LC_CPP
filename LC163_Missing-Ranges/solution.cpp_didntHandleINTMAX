    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        nums.insert(nums.begin(), lower - 1); // sentinel lower bound
        nums.push_back(upper + 1); // sentinal upper bound
        
        int n = nums.size();
        
        // since we pushsed back -1 and 100, there should be at least two nums in the vector
        vector<string> result;
        int diff;
        for (int i = 1; i < n; ++i) {
            diff = nums[i] - nums[i-1];
            if (diff == 2)
                result.push_back(to_string(nums[i-1]+1));
            else if (diff > 2) 
                result.push_back(to_string(nums[i-1]+1) + "->" + to_string(nums[i]-1));
        }
        return result;
    }
