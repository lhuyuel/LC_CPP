class Solution {
public:
    // 这个是错误的思路，只适用于不连续的substr
    /*int lengthOfLongestSubstring(string s) {
        int len = s.size();
        vector<int> f(len+1,0);
        f[1] = 1;
        for (int i = 1; i < len; ++i ) {
            int j = 0;
            for (; j < i; ++j) {
                if (s[j] == s[i]) {
                    f[i+1] = f[i];
                    break;
                }
            }
            if (j == i) f[i+1] = f[i] + 1;
        }
        return f[len];
    }
    */
    int lengthOfLongestSubstring(string s) {
        int len = s.size();
        int maxLen = 0;
        int lastRepTable[256];
        fill(lastRepTable, lastRepTable+256, -1);
        int lastRepPos = -1;
        for (int i = 0 ; i < len; ++i) {
            // update lastrepeat position in the table
            if (lastRepTable[s[i]] != -1 && lastRepPos < lastRepTable[s[i]]) 
                lastRepPos = lastRepTable[s[i]];
            if ( i - lastRepPos > maxLen ) maxLen = i - lastRepPos;
            lastRepTable[s[i]] = i;
        }
        return maxLen;
    }
};