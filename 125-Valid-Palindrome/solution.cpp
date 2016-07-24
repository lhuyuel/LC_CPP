class Solution {
public:

// "race a car"
// Aba
// "0P"

    bool isPalindrome(string s) {
        if (s.size() == 0) return true;
        for (int i = 0, j = s.size()-1; i < j && i < s.size() && j < s.size();) {
            while ((s[i]==' ' || s[i] == ',') && i < s.size()) ++i;
            while ((s[j]==' ' || s[j] == ',') && j < s.size()) --j;
            if( i < s.size() && j > 0 )
                if (isalpha(s[i]) && isalpha(s[j]) ){
                    if (abs(s[i]-s[j]) != 32 && abs(s[i]-s[j]) != 0)
                        return false;
                }
                else
                    if (abs(s[i]-s[j]) != 0)
                        return false;
            }
            ++i, --j;

        }
        return true;
    }
};