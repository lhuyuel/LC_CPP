class Solution {
public:
    // DP: f(i) = ( f(i-1) & isValid(data[i]) ) || ( f(i-2) & isValid(data[i-1]data[i]) )  
    //            || ( f(i-3) & isValid(data[i]) ) || ( f(i-4) & isValid(data[i]) ) 
    
    /*
    For 1-byte character, the first bit is a 0, followed by its unicode code.
    For n-bytes character, the first n-bits are all one's, the n+1 bit is 0, followed by n-1 bytes with most significant 2 bits being 10.
    */
    
    
    // data = [197, 130, 1], which represents the octet sequence: 11000101 10000010 00000001.
    bool isValid(vector<int> &d) {
        int n = d.size();
        int mask = 1;
        if (n == 1) {
             mask <<= 7;
            if ((d[0] & mask)) return false;
        }
        else {
            mask <<= 8; // currently mask = (100 000 000)2
            for (int i = 0; i <  n; ++i) {
                mask >>= 1;
                if (!(d[0] & mask)) return false;
            }
            mask >>= 1; // the n+1 bit
            if ((d[0]&mask)) return false; 
            for (int i = 1; i < n; ++i) {
                mask = 1;
                mask <<= 7; // check 8th bit
                if (!(d[i]&mask)) return false;
                mask >>= 1; // check 7th bit
                if ((d[i]&mask)) return false;
            }
        }
        return true;
    }

    bool validUtf8(vector<int>& data) {
        int n = data.size();
        vector<bool> dp(n+1, false);
        dp[0] = true;
        for (int i = 1; i <= n; ++i) {
            vector<int> toCheck;
            vector<bool> split(4,false);
            for (int j = 1; j <= 4; ++j) {
                if (i-j >= 0) {
                    toCheck.insert(toCheck.begin(),data[i-j]);
                    split[j-1] = dp[i-j] && isValid(toCheck);
                    dp[i] = dp[i] || split[j-1];
                }
            }
        }
        return dp[n];
    }
};