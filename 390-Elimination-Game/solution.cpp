class Solution {
public:

/*
Input:
n = 9,
-1  2 -3  4 -5  6 -7  8 -9
-1  2 -3 -4 -5  6 -7 -8 -9
-1 -2 -3 -4 -5  6 -7 -8 -9

n = 1, 1     f(1) = 1
n = 2, -1, 2 f(2) = 2
n = 3, -1, 2, -3  f(3) = 2
n = 4, -1 ,2, -3, -4 f(4) = 2
n = 5, -1 ,2, -3, -4, -5 f(5) = 2
n = 6, -1 ,-2, -3, 4, -5 , -6 f(6) = 4
n = 7, -1 ,-2, -3, 4, -5 , -6, -7   f(7) = 4
n = 8, -1 ,-2, -3, -4, -5 , 6, -7, -8  f(8) = 6
f(9) = f(8) = 6 
 
*/

    int lastRemaining(int n) {
        int last = n, gap = 1;
        bool direction = false;
        for (;n > 1; n >>= 1,direction = !direction, gap <<= 1) {
            if ((n&1) || direction) last -= gap;
        }
        return last;
    }
};