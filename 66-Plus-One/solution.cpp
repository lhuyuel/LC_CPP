class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size()-1, carry = 1;
        while (digits[i] + carry > 9) {
            digits[i--] = 0;
            carry = 1;
        }
        if (i == -1) digits.insert(digits.begin(),1);
        else digits[i] += 1;
        return digits;
    }
};