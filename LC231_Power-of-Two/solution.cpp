class Solution {
public:
/*  一般解法
    bool isPowerOfTwo(int n) {
        if (n < 1) return false;
        return (!(n&(n-1)));
    }
*/ 
    bool isPowerOfTwo(int n) {
        bitset<64> b(n);
        return b.count()==1;
    }
};