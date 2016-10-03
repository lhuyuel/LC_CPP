class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> table(52,0);
        for (int i = 0; i < s.length(); ++i) {
            char cur = (s[i] >= 'a') ? s[i] - 'a' : s[i] - 'A' + 26; // store lower case in first 26 pos
            ++table[cur];
        }
        
        int count = 0;
        bool oddExist = false;
        for (int i = 0; i < table.size(); ++i) {
            count += table[i];
            if (table[i] & 1)  --count, oddExist = true;
        }
        return oddExist ? count + 1 : count;
    }
};