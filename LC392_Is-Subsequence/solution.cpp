class Solution {
public:
    // O(n) for brute force
    // test case: s = "abc", t = "ahbgdc"
    // test case2: s = "axc", t = "ahbgdc"
    bool isSubsequence(string s, string t) {
        int m = s.length(), n = t.length();
        if (m > n) return false;
        // for each char in s, check if exsit in t
        int i = 0, j = 0;
        while (i < m) {
            while (j < n && s[i] != t[j]) {++j;}
            if (j == n) return false; // didn't find match
            // at this point, s[i] equals to t[j]
            ++i,++j;
        }
        if (i == m) return true;
        else return false;
    }
};