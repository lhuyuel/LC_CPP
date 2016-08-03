// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if (n == 1) return 1;
        int start = 1, end = n, mid = 0;
        while (start != end) {
            mid = (end - start)/2 + start;
            if (isBadVersion(mid)) end = mid;
            else start = mid;
        }
        return start;
    }
};