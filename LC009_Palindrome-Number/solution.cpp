class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int num = x, sum = 0;
        while (num > 0){
            sum = sum*10 + num%10;
            num /= 10;
        }
        return sum == x;
    }
};