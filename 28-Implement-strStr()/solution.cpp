class Solution {
public:
    // could use KMP algorithm
    
    // haystack = "abcdfg", needle = "cde"
    // abcd      e    | expected -1
    // ""    "a"
    //  "abcdefcdg"     cdg
    // Brute Force
    
    // "aaaaa"   size =5
    // "bba"     size = 3

    int strStr(string haystack, string needle) {
        if (haystack == needle || needle == "") return 0;
        
        for (int i = 0; i < haystack.size(); ) {
            while (haystack[i] != needle[0]) ++i;
            int j = 0;
            for (; j < haystack.size()-i && j < needle.size(); ++j ) { 
                if( haystack[j+i] != needle[j]) 
                    break;
            }
            if (j == needle.size()) return i;
        }
        return -1;
    }
};