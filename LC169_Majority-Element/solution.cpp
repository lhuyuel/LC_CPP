class Solution {
public:
/* 方法1： sort     O(nlogn)
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return nums[nums.size()/2];
    }
*/
    // Boyer-Moore    O(n)
    int majorityElement(vector<int> &num) {
        int maj;
        for (int count = 0, i = 0; i < num.size() && count <= num.size()/2; i++){
            if (count == 0){
                maj = num[i];
                count++;
            }
            else num[i] == maj ? count++ : count--;
        }
        return maj;
    }
};