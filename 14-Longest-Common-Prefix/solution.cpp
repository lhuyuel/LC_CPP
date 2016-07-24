class Solution {
public:
    string commonPrefix(string str1, string str2) {
        if (!str1.size() || !str2.size()) return "";
        int i = 0;
        for (; i < str1.size() && i < str2.size(); ++i) {
            if (str1[i] != str2[i]) break;
        }
        return str1.substr(0,i);
    }
    
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        else if (strs.size() == 1) return strs[0];
        
        string cmPrefix = commonPrefix(strs[0], strs[1]);
        
        for (int i = 1; i < strs.size(); ++i) {
            cmPrefix = commonPrefix(cmPrefix, strs[i]);
        }
        return cmPrefix;
    }
};