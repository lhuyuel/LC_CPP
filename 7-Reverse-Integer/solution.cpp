class Solution {
public:
    int reverse(int x) {
        
        if (x < 0) return -1 * reverse(-1*x);
        int sum = 0;
        while (x > 0) {
            if (sum <= INT_MIN/10 || sum >= INT_MAX/10) return 0;
            sum = sum * 10 + x % 10;
            x /= 10;
        }
        return sum;
    }
};