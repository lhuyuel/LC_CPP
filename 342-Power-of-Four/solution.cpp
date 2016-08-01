class Solution {
public:
    // get num&1, if 1 return false, else >>1
    bool isPowerOfFour(int num) {
        if (num < 1) return false;
        if (num == 1) return true;
        int count = 0;
        while(num > 1) {
            if ((num&1) != 0) return false;
            ++count;
            num = num >> 1;
        }
        return (count&1) == 0;
    }
};