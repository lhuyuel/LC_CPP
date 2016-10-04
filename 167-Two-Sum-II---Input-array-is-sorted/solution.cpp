class Solution {
public:
    // return index pair
    vector<int> twoSum(vector<int>& numbers, int target) {
        int idx1 = -1, idx2 = -1, n = numbers.size();
        vector<int> result;
        for (idx1 = 0, idx2 = n-1; idx1 < idx2; ) {
            int sum = numbers[idx1] + numbers[idx2];
            if (sum == target) { 
                result.push_back(idx1+1);
                result.push_back(idx2+1);
                break;
            }
            sum < target ? ++idx1 : --idx2;
        }
        return result;
    }
};