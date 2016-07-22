class Solution {
public:
    // vowels are: a e i o u ?
    string reverseVowels(string s) {
        bool vowelTable[52];
        vowelTable['a'-'A'] = true;
        vowelTable['e'-'A'] = true;
        vowelTable['i'-'A'] = true;
        vowelTable['o'-'A'] = true;
        vowelTable['u'-'A'] = true;
        vowelTable['A'-'A'] = true;
        vowelTable['E'-'A'] = true;
        vowelTable['I'-'A'] = true;
        vowelTable['O'-'A'] = true;
        vowelTable['U'-'A'] = true;
        
        for (int i = 0, j = s.size()-1; i < j;) {
            while (i<j && !vowelTable[s[i]-'A']) ++i;
            while (i<j && !vowelTable[s[j]-'A']) --j;
            swap(s[i++],s[j--]);
        }
        return s;
    }
};