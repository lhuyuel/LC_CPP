class Solution {
public:
    // dp, f[i,j] = if s[i] == s[j] f[i+1,j-1] +2  ,     result+=s[i]
    //                else max(f[i+1,j], f[i,j-1])
    string longestPalindrome(string s) {
        string result = "";
        int n = s.length();
        int maxLen = 0, begin = 0;
        vector<vector<bool>> dp(n, vector<bool>(n,false));
        for (int i = 0; i < n; ++i)
            dp[i][i] = true;
        
        for (int i = n-1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                if ( (i + 1 > j -1 || dp[i+1][j-1] ) && s[i] == s[j]) {
                    dp[i][j] = true;
                    if (j-i+1 > maxLen) {
                        maxLen = j-i+1;
                        begin = i;
                    }
                }
            }
        }
        return s.substr(begin,maxLen);
    }
};