int maxXor(int l, int r) {
    int xorVal = l ^ r;  // eliminate the common prefix
    int maxXor = 1;
    while (xorVal) {     // count how many digits(k) are there in this xorVal, maxXor = pow(2,k) - 1
        maxXor <<= 1;
        xorVal /= 2;
    }
    return maxXor - 1;
}
