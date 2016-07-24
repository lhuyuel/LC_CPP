class Solution {
public:

// "race a car"
// Aba
    bool isPalindrome(string s) {
        if (s.size() == 0) return true;
        for (int i = 0, j = s.size()-1; i < j;) {
            while(!isalpha(s[i])) ++i;
            while(!isalpha(s[j])) --j;
            if( abs(s[i]-s[j]) != 0 && abs(s[i]-s[j]) != 26) {
                return false;
            }
            ++i, --j;

        }
        return true;
    }
};