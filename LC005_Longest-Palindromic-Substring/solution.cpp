class Solution {
public:
    // dp, f[i,j] = if s[i] == s[j] f[i+1,j-1] +2  ,     result+=s[i]
    //                else max(f[i+1,j], f[i,j-1])
    string longestPalindrome(string s) {
        if (s.size() < 2)
            return s;
        int len = s.size(), max_left = 0, max_len = 1, left, right;
        
        /* Did some pruning here, if the remainning substring's length is less than current max len, 
        there is no way to get a longer palindrome string. */
        int start = 0;
        while ( start < len && (len-start)*2 > max_len) {
            left = right = start;
            //  March through the continueous same characters
            while (right < len - 1 && s[right + 1] == s[right])
                ++right;
            start = right + 1;
            while (right < len - 1 && left > 0 && s[right + 1] == s[left - 1]) {
                ++right;
                --left;
            }
            if (max_len < right - left + 1) {
                max_left = left;
                max_len = right - left + 1;
            }
        }
        return s.substr(max_left, max_len);
    }
};