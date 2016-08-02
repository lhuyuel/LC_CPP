// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int start = 1, end = n, mid = 0;
        while (1) {
            mid = (end-start)/2 + start;
            int feedback = guess(mid);
            if (feedback == 0) return mid;
            else if (feedback == 1) start = mid + 1;
            else end = mid - 1;
        }
    }
};