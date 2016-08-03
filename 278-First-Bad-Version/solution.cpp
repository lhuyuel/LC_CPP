// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int start = 1, end = n, mid = 0;
        while (1) {
            mid = (end - start)/2 + start;
            if (isBadVersion(mid)) 
                if (isBadVersion(mid+1)) start = mid +1;
                else return mid;
            else 
                if (isBadVersion(mid -1)) return mid-1;
                else end = mid-1;
        }
    }
};