class Solution {
public:
    int climbStairs(int n) {
        if (n < 2) return n;
        int pre_1 = 1, pre_2 = 1;
        int cur = 0;
        for (int i = 1; i < n; ++i) {
            cur = pre_1 + pre_2;
            pre_1 = pre_2;
            pre_2 = cur;
        }
        return cur;
    }
};