// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int start = 1, end = n, mid = 0;
        while (1) {
            if (start == end) return start;
            mid = (end - start)/2 + start;
            if (isBadVersion(mid)) start = mid;
            else end = mid;
        }
    }
};