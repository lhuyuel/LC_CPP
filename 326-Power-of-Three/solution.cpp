class Solution {
public:
    // 求出最大的3的指数幂，然后除以n
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        int t = pow(3,(int)(log(INT_MAX)/log(3)));
        return t%n == 0;
    }
};