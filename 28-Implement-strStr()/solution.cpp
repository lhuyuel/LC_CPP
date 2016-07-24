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
        if (haystack == needle) return 0;
        int pre = 0;
        for (int i = 0; i < haystack.size(); ) {
            while (haystack[i] != needle[0]) ++i;
            pre = i + 1;
            int j = 0;
            for (; i< haystack.size() && j < needle.size(); ++j ) { 
                if( haystack[i++] != needle[j]) 
                    break;
            }
            if (j == needle.size()) return pre-1;
            // rest i
            i = pre;
        }
        return -1;
    }
};