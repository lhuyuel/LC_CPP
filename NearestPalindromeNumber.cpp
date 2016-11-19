// nearest palindrome
// test case: 129 should return 131, not 121
int  nearestPalin(int num) {
    if (num >= 0 && num < 10) return num;
    
    int countDgt = 1, tmp = num, mask_h = 1;
    while (tmp /= 10) {
        ++countDgt;
        mask_h *= 10;
    }
    bool isOdd = (countDgt & 1) ? true : false;
    countDgt >>= 1; // check the first half of the number
    int mask_l = 1;
    int result = 0;
    tmp = num;
    while (countDgt > 0) {
        int h = tmp / mask_h;
        int l = (tmp / mask_l) % 10;
        result += h * mask_h + h * mask_l;
        tmp = tmp - h * mask_h - l * mask_l;
        mask_h /= 10;
        mask_l *= 10;
        --countDgt;
    }
    // if the number has odd digits, then there are three choices:
    // mid -1, mid, mid +1 for the middle digit. We need to pick the
    // one the differs the least form the orginal number
    if (isOdd) {
        int result1 = result + tmp;
        int result2 = result + tmp - mask_l;
        int result3 = result + tmp + mask_l;
        
        int diff1 = abs(result1 - num);
        int diff2 = abs(result2 - num);
        int diff3 = abs(result3 - num);

        if (diff1 < diff2) {
            if (diff1 < diff3) result = result1;
            else result = result3;
        }
        else {
            if (diff2 < diff3) result = result2;
            else result = result3;
        }
        
    }
    return result;
}
