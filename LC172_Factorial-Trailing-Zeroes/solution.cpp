class Solution {
public:

    int trailingZeroes(int n) {
        int count = 0;
        for (int i = n/5; i > 0; i /= 5) count += i;
        return count;
    }
};