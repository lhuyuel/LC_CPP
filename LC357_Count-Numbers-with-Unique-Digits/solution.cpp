class Solution {
public:
    // 这题被题目的example领到歧途了。。。例子举的是n = 2，excluding 11,22,33...,99
    // 然后我就想用所有数-重复数来算，殊不知直接算才更简单。。。
    // f(1) = 1; f(2) = 9*9 + f(1); f(3) = 9*9*8 + f(2) ...
    
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        if (n == 1) return 10;
        if (n == 2) return 91;
        int base = 81, cur = 91;
        for (int i = 2; i < n && i <= 9; ++i) {
            base *= (10-i);
            cur += base;
        }
        return cur;
    }
};