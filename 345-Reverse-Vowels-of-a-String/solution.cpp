class Solution {
public:
    // vowels are: a e i o u ?
    string reverseVowels(string s) {
        unordered_map<char,bool> vowelTable = {
            {'a',true},
            {'e',true},
            {'i',true},
            {'o',true},
            {'u',true},
            {'A',true},
            {'E',true},
            {'I',true},
            {'O',true},
            {'U',true}};
        
        for (int i = 0, j = s.size()-1; i < j;) {
            while (vowelTable.find(s[i]) == vowelTable.end()) ++i;
            while (vowelTable.find(s[j]) == vowelTable.end()) --j;
            if (i < j) swap(s[i++],s[j--]);
            else break;
        }
        return s;
    }
};