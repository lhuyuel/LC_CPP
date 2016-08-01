class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == 1) return true;
        else if (n < 1 || (n&1)) return false;
        return (!(n&(n-1)));
    }
};