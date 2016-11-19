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
    while (countDgt > 0) {
        int h = num / mask_h;
        int l = (num / mask_l) % 10;
        result += h * mask_h + h * mask_l;
        num = num - h * mask_h - l * mask_l;
        mask_h /= 10;
        mask_l *= 10;
        --countDgt;
    }
    if (isOdd) result += num;
    return result;
}
