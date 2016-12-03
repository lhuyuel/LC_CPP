class Solution {
public:
/*当从右向左删除时，或者当n为基数时，最后一个数向左移动gap位*/
    int lastRemaining(int n) {
        int last = n, gap = 1;
        bool direction = false;
        for (;n > 1; n >>= 1,direction = !direction, gap <<= 1) {
            if ((n&1) || direction) last -= gap;
        }
        return last;
    }
};