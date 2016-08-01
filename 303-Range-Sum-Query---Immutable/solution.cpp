class NumArray {
public:

    vector<int> sumN;
    NumArray(vector<int> &nums) {
        if (nums.size() == 0) return;
        sumN.push_back(0);
        sumN.push_back(nums[0]);
        for (int i = 1; i < nums.size(); ++i) {
            sumN.push_back(nums[i]+sumN[i]);
        }
    }

    int sumRange(int i, int j) {
        if (i > j) return INT_MIN;
        return sumN[j+1] - sumN[i];
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);