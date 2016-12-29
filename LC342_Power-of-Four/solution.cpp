    // 1. should only have 1 '1'
    // 2. have even number of '0's
    bool isPowerOfFour(int num) {
        if (num <= 0 || (num & (num - 1)) != 0) 
            return false;
        int count = 0;
        while (num > 1) {
            num >>= 1;
            ++count;
        }
        return !(count & 1);
    }
